#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct process {
    int pid;
    int status; // 1 就绪，2等待 3运行
    int bt; // 运行所需时间
    int priority; // 优先级
    int at; // 到达时间
    int wt; // 等待时间
    int ave_wt; // 平均等待时间
    bool visited;
    int lasttime;
    int has_run; // 已经运行时间
    bool operator < (const process &a) const
    {
      return a.priority < priority;
    }
} process;

void FIFO(int n, vector<process> p);
void RR(int n, vector<process> p);
void highPriority(int n, vector<process> p);
bool compareAt(process a, process b);
int calculate(int at, int bt);
int calcTime(int nowtime, int bt);

int main() {
  vector<process> p(10);
  int n;
  cout << "请输入进程数量：";
  cin >> n;
  int i, j; /* count temp; */

  cout << "输入作业的信息：进程号 到达时间 运行时间 优先数（0最高）" << endl;
  for (i = 0; i < n; i++) {
    cin >> p[i].pid >> p[i].at >> p[i].bt >> p[i].priority;
    p[i].wt = 0; /* init */
    p[i].ave_wt = 0;
    p[i].status = 1;
    p[i].visited = false;
    p[i].has_run = 0;
    p[i].lasttime = p[i].at;
  }

  cout << "FIFO:" << endl;
  FIFO(n, p);
  cout << "------------------" << endl;
  cout << "highPriority:" << endl;
  highPriority(n, p);
  cout << "------------------" << endl;
  cout << "RR:" << endl;
  RR(n, p);

  return 0;
}

int calculate(int at, int bt) {
  int ah = at / 100;
  int am = at - ah * 100;
  int bh = bt / 100;
  int bm = bt - bh * 100;

  int m = bm - am;
  int h = bh - ah;
  return h * 60 + m;
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

bool compareAt(process a, process b) {
  return (a.at <= b.at);
}

void FIFO(int n, vector<process> p) {
//  sort(p.begin(), p.end(), compareAt);
  int wtSum = 0;
  p[0].wt = 0;
  int i;
  // calculate wait time
  for (i = 1; i < n; i++) {
    int interval = p[i - 1].wt + p[i].bt - calculate(p[i - 1].at, p[i].at);
    p[i].wt = interval > 0 ? interval : 0;
  }

  cout << "进程号 运行时间 等待时间" << endl;
  for (i = 0; i < n; i++) {
    wtSum += p[i].wt;
    printf("%3d %6d %8d \n", p[i].pid,p[i].bt, p[i].wt);
  }
  printf("平均等待时间为：%.2f\n", float(wtSum / n));
}

void highPriority(int n, vector<process> p) {
  priority_queue<process> waitprocess;
  int wtSum = 0;
  process curRun;
  int nowtime = p[0].at;
  int finishtime = nowtime;
  p[0].status = 3;
  p[0].visited = true;
  waitprocess.push(p[0]);

//  cout << "当前时间 进程号  进入时间 运行时间  已经运行时间" << endl;
  cout << "进程号  进入时间 等待时间" << endl;
  while (!waitprocess.empty()) {
    curRun = waitprocess.top();
    waitprocess.pop();

    // 计算当前运行的进程预计完成时间
    // 把完成时间以内的其他已经到达的进程 加入就绪队列
    finishtime = calcTime(nowtime, curRun.bt - curRun.has_run);
    for (int i = 0; i < n; i++) {
      if (!p[i].visited && p[i].at < finishtime) {
        p[i].visited = true;
        waitprocess.push(p[i]);
      }
    }
    // 看就绪队列里有没有比当前运行进程的优先级高的
    if (!waitprocess.empty()) {
      // 优先级高的抢占CPU
      // 被抢占的进程放回就绪队列里
      if (waitprocess.top().priority < curRun.priority) {

        if (waitprocess.top().at > nowtime) {
          curRun.has_run = waitprocess.top().at - nowtime;

          nowtime = waitprocess.top().at;
          curRun.lasttime = nowtime;
        } else {
          int nexttime = calcTime(nowtime, waitprocess.top().bt - waitprocess.top().has_run);
          curRun.has_run += calculate(nowtime, nexttime);

          nowtime = calcTime(nowtime, curRun.has_run);
          curRun.lasttime = nowtime;
        }
        waitprocess.push(curRun);

      } else {
        // 没有：让当前进程进行完，更新当前时间
        nowtime = finishtime;
      }
    } else {
      nowtime = finishtime;
    }


    if (calculate(curRun.at, nowtime) != curRun.has_run) {
      curRun.wt = calculate(curRun.lasttime, nowtime) + curRun.wt - (curRun.bt - curRun.has_run);
    }
//    printf("%6d %3d %9d %9d %9d %9d\n", nowtime, curRun.pid, curRun.at, curRun.bt, curRun.has_run, curRun.wt);
    if (calcTime(curRun.at, curRun.bt + curRun.wt) == nowtime) {
      wtSum += curRun.wt;
      printf("%3d %9d %9d\n", curRun.pid, curRun.at, curRun.wt);
    }
    // 队列空了但是有未执行的进程
    if(waitprocess.empty()) {
      for (int i = 0; i < n; i++) {
        if (p[i].at >= nowtime && !p[i].visited) {
          waitprocess.push(p[i]);
          p[i].visited = true;
          nowtime = p[i].at;
          break;
        }
      }
    }
  }
  printf("平均等待时间为：%.2f\n", float(wtSum / n));
}

void RR(int n, vector<process> p) {
  int q = 10; // 时间片
  vector<process> waitprocess;
  vector<process> result;
  int wtSum = 0;
  p[0].visited = true;
  waitprocess.push_back(p[0]);
  int nowtime = p[0].at;

  cout << "进程号  进入时间 运行时间 等待时间" << endl;
  while (!waitprocess.empty()) {
    process curRun = waitprocess.front();
    waitprocess.erase(waitprocess.begin());

    nowtime = calcTime(nowtime, q);
    curRun.has_run += q;
    for (int i = 0; i < n; ++i) {
      if (!p[i].visited && p[i].at <= nowtime) {
        p[i].visited = true;
        waitprocess.push_back(p[i]);
      }
    }
//    printf("%3d %6d %9d %9d\n", curRun.pid, curRun.at, curRun.bt, nowtime);
    for (int j = 0; j < waitprocess.size(); ++j) {
      waitprocess[j].wt += 10;
    }
    if (curRun.has_run < curRun.bt) {
      waitprocess.push_back(curRun);
    } else {
      curRun.wt = calculate(curRun.at, nowtime) - curRun.bt;
      wtSum += curRun.wt;
      printf("%3d %6d %9d %9d\n", curRun.pid, curRun.at, curRun.bt, curRun.wt);
    }
  }

  printf("平均等待时间为：%.2f\n", float(wtSum / n));
}