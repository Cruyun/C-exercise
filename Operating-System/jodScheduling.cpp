#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct process {
    int jid;
    int at; /* arrival time */
    int bt; /* burst time */
    int wt; /* wait time */
    double rr; /* rate */
    bool visited;
    bool operator < (const process &a) const
    {
      return a.bt < bt;
    }
} process;

void FIFO(int n, vector<process> p);
void SJF(int n, vector<process> p);
void HRRN(int n, vector<process> p);

int main() {
  vector<process> p(10);
  int n; /* num of processes */
  cout << "input the num of processes: ";
  cin >> n;
  int i, j; /* count temp; */

  cout << "input the info of process: no, arrival time, burst time, pivilege:" << endl;
  for (i = 0; i < n; i++) {
    cin >> p[i].jid >> p[i].at >> p[i].bt;
    p[i].wt = 0; /* init */
    p[i].rr = 0.0; /* init */
    p[i].visited = false;
  }
  FIFO(n, p);
  SJF(n, p);
  HRRN(n, p);

  return 0;
}
/**
  * a: arrival time of process a
    b: arrival time of process a
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

void FIFO(int n, vector<process> p) {
  p[0].wt = 0;
  int i;
  // calculate wait time
  for (i = 1; i < n; i++) {
    int interval = p[i - 1].wt + p[i].bt - calculate(p[i - 1].at, p[i].at);
    p[i].wt = interval > 0 ? interval : 0;
  }

  cout << "进程号  运行时间  等待时间" << endl;
  for (i = 0; i < n; i++) {
    cout << p[i].jid << "  " << p[i].bt << "  " << p[i].wt << endl;
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

void SJF(int n, vector<process> p) {
  priority_queue<process> waitProcess;
  process curRun;
  int nowtime = p[0].at;
  waitProcess.push(p[0]);
  p[0].visited = true;

  cout << "进程号  进入时间 运行时间  结束运行时间" << endl;

  while (!waitProcess.empty()) {
    curRun = waitProcess.top();
    waitProcess.pop();
    nowtime = calcTime(nowtime, curRun.bt);

    cout << curRun.jid << "   " << curRun.at << " " << curRun.bt << "  " << nowtime  << endl;


    for (int i = 0; i < n; i++) {
      if (p[i].at <= nowtime && !p[i].visited) {
        waitProcess.push(p[i]);
        p[i].visited = true;
      }
    }

    if(waitProcess.empty()) {
      for (int i = 0; i < n; i++) {
        if (p[i].at >= nowtime && !p[i].visited) {
          waitProcess.push(p[i]);
          p[i].visited = true;
          nowtime = p[i].at;
          break;
        }
      }
    }
  }
}

bool comparisionRR(process a, process b) {
  return (a.rr < b.rr);
}

void HRRN(int n, vector<process> p) {
  vector<process> waitProcess;
  process curRun;
  int nowtime = p[0].at;
  p[0].visited = true;
  waitProcess.push_back(p[0]);

  cout << "进程号  进入时间  运行时间  结束运行时间" << endl;

  while (!waitProcess.empty()) {
    for (int i = 0; i < waitProcess.size(); i++) {
      waitProcess[i].wt = calculate(waitProcess[i].at, nowtime);
      waitProcess[i].rr = double((waitProcess[i].wt  +waitProcess[i].bt))/ double(waitProcess[i].bt);
    }
    sort(waitProcess.begin(), waitProcess.end(), comparisionRR);
    curRun = waitProcess.back();
    waitProcess.pop_back();
    nowtime = calcTime(nowtime, curRun.bt);

    cout << curRun.jid << "   " << curRun.at << " " << curRun.bt << "  " << nowtime << endl;


    for (int i = 0; i < n; i++) {
      if (p[i].at <= nowtime && !p[i].visited) {
        p[i].visited = true;
        waitProcess.push_back(p[i]);
      }
    }

    if(waitProcess.empty()) {
      for (int i = 0; i < n; i++) {
        if (p[i].at >= nowtime && !p[i].visited) {
          p[i].visited = true;
          waitProcess.push_back(p[i]);
          nowtime = p[i].at;
          break;
        }
      }
    }
  }
}