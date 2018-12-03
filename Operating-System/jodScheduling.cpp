#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct job {
  int jid;
  int at; /* arrival time */
  int bt; /* burst time */
  int wt; /* wait time */
  double rr; /* rate */
  bool visited;
  bool operator < (const job &a) const
  {
    return a.bt < bt;
  }
} job;

void FIFO(int n, vector<job> p);
void SJF(int n, vector<job> p);
void HRRN(int n, vector<job> p);
bool comparisionAt(job a, job b);

int main() {
  vector<job> p(10);
  int n; /* num of jobs */
  cout << "请输入作业数量：";
  cin >> n;
  int i, j; /* count temp; */

  cout << "输入作业的信息：作业号 到达时间 运行时间" << endl;
  for (i = 0; i < n; i++) {
    cin >> p[i].jid >> p[i].at >> p[i].bt;
    p[i].wt = 0; /* init */
    p[i].rr = 0.0; /* init */
    p[i].visited = false;
  }
  
  cout << "FIFO:" << endl;
  FIFO(n, p);
  cout << "------------------" << endl;
  cout << "SJF:" << endl;
  SJF(n, p);
  cout << "------------------" << endl;
  cout << "HRRN:" << endl;
  HRRN(n, p);

  return 0;
}
/**
  * a: arrival time of job a
    b: arrival time of job a
  return time interval(minute)
**/

int calculate(int at, int bt) {
  int ah = at / 100;
  int am = at - ah * 100;
  int bh = bt / 100;
  int bm = bt - bh * 100;

  int m = bm - am;
  int h = bh - ah;
  return h * 60 + m;
}

bool comparisionAt(job a, job b) {
  return (a.at <= b.at);
}
 
void FIFO(int n, vector<job> p) {
  // sort(p.begin(), p.end(), comparisionAt);
  p[0].wt = 0;
  int i;
  // calculate wait time
  for (i = 1; i < n; i++) {
    int interval = p[i - 1].wt + p[i].bt - calculate(p[i - 1].at, p[i].at);
    p[i].wt = interval > 0 ? interval : 0;
  }

  cout << "进程号 运行时间 等待时间" << endl;
  for (i = 0; i < n; i++) {
    printf("%3d %6d %8d \n", p[i].jid,p[i].bt, p[i].wt);
  }
}


int calcTime(int nowtime, int bt) {
  int nowMinute = nowtime % 100;
  int nowHour = nowtime / 100;
  int newMinutue = nowMinute;
  if (bt + nowMinute >= 60) {
    nowHour += 1;
  }
  newMinutue = (bt + nowMinute) % 60;
  return nowHour * 100 + newMinutue;
}

void SJF(int n, vector<job> p) {
  priority_queue<job> waitjob;
  job curRun;
  int nowtime = p[0].at;
  waitjob.push(p[0]);
  p[0].visited = true;

  cout << "进程号  进入时间 运行时间  结束运行时间" << endl;

  while (!waitjob.empty()) {
    curRun = waitjob.top();
    waitjob.pop();
    nowtime = calcTime(nowtime, curRun.bt);

    printf("%3d %9d %9d %9d\n",curRun.jid, curRun.at, curRun.bt, nowtime);
    for (int i = 0; i < n; i++) {
      if (p[i].at <= nowtime && !p[i].visited) {
        waitjob.push(p[i]);
        p[i].visited = true;
      }
    }

    if(waitjob.empty()) {
      for (int i = 0; i < n; i++) {
        if (p[i].at >= nowtime && !p[i].visited) {
          waitjob.push(p[i]);
          p[i].visited = true;
          nowtime = p[i].at;
          break;
        }
      }
    }
  }
}

bool comparisionRR(job a, job b) {
  return (a.rr < b.rr);
}

void HRRN(int n, vector<job> p) {
  vector<job> waitjob;
  job curRun;
  int nowtime = p[0].at;
  p[0].visited = true;
  waitjob.push_back(p[0]);

  cout << "进程号  进入时间  运行时间  结束运行时间" << endl;

  while (!waitjob.empty()) {
    for (int i = 0; i < waitjob.size(); i++) {
      waitjob[i].wt = calculate(waitjob[i].at, nowtime);
      waitjob[i].rr = double((waitjob[i].wt  +waitjob[i].bt))/ double(waitjob[i].bt);
    }
    sort(waitjob.begin(), waitjob.end(), comparisionRR);
    curRun = waitjob.back();
    waitjob.pop_back();
    nowtime = calcTime(nowtime, curRun.bt);

    printf("%3d %9d %9d %9d\n",curRun.jid, curRun.at, curRun.bt, nowtime);


    for (int i = 0; i < n; i++) {
      if (p[i].at <= nowtime && !p[i].visited) {
        p[i].visited = true;
        waitjob.push_back(p[i]);
      }
    }

    if(waitjob.empty()) {
      for (int i = 0; i < n; i++) {
        if (p[i].at >= nowtime && !p[i].visited) {
          p[i].visited = true;
          waitjob.push_back(p[i]);
          nowtime = p[i].at;
          break;
        }
      }
    }
  }
}
