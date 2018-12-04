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
void highPriority1(int n, vector<process> p);
void highPriority2(int n, vector<process> p);
bool compareAt(process a, process b);
int calculate(int at, int bt);
int calcTime(int nowtime, int bt);
void FB(int n, vector<process> p);

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

  cout << "------------------------------------" << endl;
  cout << "FIFO:" << endl;
  cout << "------------------------------------" << endl;
  FIFO(n, p);
  cout << "------------------------------------" << endl;
  cout << "抢占式 highPriority:" << endl;
  cout << "------------------------------------" << endl;
  highPriority1(n, p);
  cout << "------------------------------------" << endl;
  cout << "非抢占式 highPriority:" << endl;
  cout << "------------------------------------" << endl;
  highPriority2(n, p);
  cout << "------------------------------------" << endl;
  cout << "RR:" << endl;
  cout << "------------------------------------" << endl;
  RR(n, p);
  cout << "------------------------------------" << endl;

  cout << "FB" << endl;
  cout << "------------------------------------" << endl;
  FB(n, p);
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

void highPriority1(int n, vector<process> p) {
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
    bool flag = false;
    for (int j = nowtime; j <= finishtime; j++) {
      for (int i = 0; i < n; i++) {
        if (!p[i].visited && p[i].at < j) {
          p[i].visited = true;
          int k = i;
          waitprocess.push(p[i]);
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
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

void highPriority2(int n, vector<process> p) {
  priority_queue<process> waitprocess;
  process curRun;
  int nowtime = p[0].at;
  int wtSum = 0;
  waitprocess.push(p[0]);
  p[0].visited = true;

  cout << "进程号  进入时间 运行时间  等待时间" << endl;

  while (!waitprocess.empty()) {
    curRun = waitprocess.top();
    waitprocess.pop();
    nowtime = calcTime(nowtime, curRun.bt);
    curRun.wt = calculate(curRun.at, nowtime);
    wtSum += curRun.wt;

    printf("%3d %9d %9d %9d\n",curRun.pid, curRun.at, curRun.bt, curRun.wt);
    for (int i = 0; i < n; i++) {
      if (p[i].at <= nowtime && !p[i].visited) {
        waitprocess.push(p[i]);
        p[i].visited = true;
      }
    }

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
  int q = 5; // 时间片
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

    int wt = 0;
    if (curRun.bt - curRun.has_run >= q) {
      curRun.has_run += q;
      wt = q;
      nowtime = calcTime(nowtime, q);
    } else {
      wt = curRun.bt - curRun.has_run;
      nowtime = calcTime(nowtime, wt);
      curRun.has_run = curRun.bt;
    }

    for (int i = 0; i < n; ++i) {
      if (!p[i].visited && p[i].at <= nowtime) {
        p[i].visited = true;
        waitprocess.push_back(p[i]);
      }
    }
//    printf("%3d %6d %9d %9d\n", curRun.pid, curRun.at, curRun.bt, nowtime);
    for (int j = 0; j < waitprocess.size(); ++j) {
      waitprocess[j].wt += wt;
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

void FB(int n, vector<process> p) {
  vector<process> q1;
  vector<process> q2;
  vector<process> q3;
  int p1 = 5, p2 = 10, p3 = 15;
  int nowtime = p[0].at;
  process curRun;

  p[0].visited = true;
  q1.push_back(p[0]);

  while(!q1.empty() || !q2.empty() || !q3.empty()) {
    int finishtime = nowtime;
    if (!q1.empty()) {
      curRun = q1.front();
      q1.erase(q1.begin());

      if (curRun.bt - curRun.has_run > p1) {
        curRun.has_run += p1;
        nowtime = calcTime(nowtime, p1);
      } else {
        nowtime = calcTime(nowtime, curRun.bt - curRun.has_run);
        curRun.has_run = curRun.bt;
      }
      for (int i = 0; i < n; i++) {
        if (!p[i].visited && p[i].at <= nowtime) {
          p[i].visited = true;
          q1.push_back(p[i]);
          // cout << p[i].pid << "进入队列1"<<endl;
        }
      }
      if (curRun.has_run < curRun.bt) {
        // cout << curRun.pid << "在队列1运行了, 总共还剩" << curRun.bt - curRun.has_run <<"然后移到队列2"<< endl;
        q2.push_back(curRun);
      } else {
        // cout << curRun.pid << "在队列1运行完了"<<endl;
        printf("%3d %6d %9d \n", curRun.pid, curRun.at, curRun.bt);
      }
    }
    if (q1.empty() && !q2.empty()) {
      curRun = q2.front();
      q2.erase(q2.begin());

      int preHasRun = curRun.has_run;
      if (curRun.bt - curRun.has_run > p2) {
        curRun.has_run += p2;
        finishtime = calcTime(nowtime, p2);
      } else {
        finishtime = calcTime(nowtime, curRun.bt - curRun.has_run);
        curRun.has_run = curRun.bt;
      }

      for (int i = 0; i < n; i++) {
        if (!p[i].visited && p[i].at <= finishtime) {
          p[i].visited = true;
          q1.push_back(p[i]);
          // cout << p[i].pid << "进入队列1"<<endl;
        }
      }

      if (!q1.empty()) {
        if( curRun.has_run < curRun.bt ) {
          curRun.has_run = preHasRun + calculate(nowtime, q1.front().at);
        }
        nowtime = q1.front().at;
        q2.push_back(curRun);
        // cout << curRun.pid << "被抢占了，还剩" << curRun.bt - curRun.has_run <<endl;
        continue;
      } else {
        nowtime = finishtime;
      }

      if (curRun.has_run < curRun.bt) {
        // cout << curRun.pid << "在队列2运行了, 总共还剩" << curRun.bt - curRun.has_run <<"然后移到队列3"<< endl;
        q3.push_back(curRun);
      } else {
        // cout << curRun.pid << "在队列2运行完了"<<endl;
        printf("%3d %6d %9d \n", curRun.pid, curRun.at, curRun.bt);
      }
    }

    if (q1.empty() && q2.empty() && !q3.empty()) {
      curRun = q3.front();
      q3.erase(q3.begin());

      int preHasRun = curRun.has_run;
      if (curRun.bt - curRun.has_run >= p3) {
        curRun.has_run += p3;
        finishtime = calcTime(nowtime, p3);
      } else {
        finishtime = calcTime(nowtime, curRun.bt - curRun.has_run);
        curRun.has_run = curRun.bt;
      }


      for (int i = 0; i < n; i++) {
        if (!p[i].visited && p[i].at <= finishtime) {
          p[i].visited = true;
          q1.push_back(p[i]);
        }
      }
      if (!q1.empty()) {
        if( curRun.has_run < curRun.bt ) {
          curRun.has_run = preHasRun + calculate(nowtime, q1.front().at);
        }
        nowtime = q1.front().at;
        q3.push_back(curRun);
        continue;
      } else {
        nowtime = finishtime;
      }

      if (curRun.has_run < curRun.bt) {
        // cout << curRun.pid << "在队列3运行了, 总共还剩" << curRun.bt - curRun.has_run <<"然后移到队列3"<< endl;
        q3.push_back(curRun);
      } else {
        // cout << curRun.pid << "在队列3运行完了"<<endl;
        printf("%3d %6d %9d \n", curRun.pid, curRun.at, curRun.bt);
      }

    }
  }
}