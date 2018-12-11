#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define M 100 // 假设允许的空闲区表最大为100
#define N 100 // 假设最大进程数量为100
#define MINISIZE 5

typedef struct Table {
    int add; // 起始地址
    int len; // 长度
    int flag; // 空闲表0为已分配，为1则未分配； 内存分配表0为空闲，不为1为作业号
} Table;

typedef struct process {
    int pid;
    int len;
} process;

vector<Table> freeTable(M); // 空闲分配表
vector<Table> usedTable(N); // 内存分配表

// 函数声明
void initTable();
int updateTable(int pid, int fitAdd, int needlen);
int BestFit(int pid, int needlen);
int FirstFit(int pid, int needlen);
int WorstFit(int pid, int needlen);
void show();


void initTable() {
  freeTable[0].flag = 1; // 空闲表的表项为未分配
  freeTable[0].add = 1000; // 首地址为1000
  freeTable[0].len = 1024; // 假设空闲区总空间为1024kb

  for (int i = 0; i < N; i++) {
    usedTable[i].flag = 0;
  }
}

int BestFit(int pid, int needlen) {
  int fitAdd = -1; // 空闲表中最佳分区index
  int i = 0;
  int cnt = 0;

  // 找到最佳分区
  while (i < M) {
    if (freeTable[i].flag == 1 && freeTable[i].len >= needlen) {
      cnt++;
      if (cnt == 1 || freeTable[fitAdd].len > freeTable[i].len) {
        fitAdd = i;
      }
    }
    i++;
  }
  return updateTable(pid, fitAdd, needlen);
}

int FirstFit(int pid, int needlen) {
  int fitAdd = -1; // 空闲表中最佳分区index
  int i = 0;
  // 找到最佳分区
  while (i < M) {
    if (freeTable[i].flag == 1 && freeTable[i].len >= needlen) {
      fitAdd = i;
    }
    i++;
  }
  return updateTable(pid, fitAdd, needlen);
}

int WorstFit(int pid, int needlen) {
  int fitAdd = -1; // 空闲表中最佳分区index
  int i = 0;
  int cnt = 0;
  // 找到最佳分区
  while (i < M) {
    if (freeTable[i].flag == 1 && freeTable[i].len >= needlen) {
      cnt++;
      if (cnt == 1 || freeTable[fitAdd].len > freeTable[i].len ) {
        fitAdd = i;
      }
    }
    i++;
  }
  return updateTable(pid, fitAdd, needlen);
}

int updateTable(int pid, int fitAdd, int needlen) {

  int length = 0;
  int address = 0;

  // 更新空闲分配表
  if (fitAdd != -1) {
    // 假如空闲区的大小减去请求大小 <= 最小值，整个分区都分配给该进程
    if (freeTable[fitAdd].len - needlen <= MINISIZE) {
      freeTable[fitAdd].flag = 0;
      length = freeTable[fitAdd].len;
      address = freeTable[fitAdd].add;
    } else { // 切割空闲区
      length = needlen;
      address = freeTable[fitAdd].add;

      freeTable[fitAdd].add += needlen;
      freeTable[fitAdd].len -= needlen;
    }

    // 更新内存分配表
    int i = 0;
    while ( usedTable[i].flag != 0) {
      i++;
    }
    // 找到可使用的内存分配表项
    if (i < N) {
      usedTable[i].flag = pid;
      usedTable[i].add = address;
      usedTable[i].len = length;
    } else { // 内存分配表不足,撤销分配
      if (freeTable[fitAdd].flag == 0) {
        freeTable[fitAdd].flag = 1;
        freeTable[fitAdd].add = address;
        freeTable[fitAdd].len = length;
      } else { // 将分割的内存合并
        freeTable[fitAdd].add = address;
        freeTable[fitAdd].len += length;
      }
    }
  } else {
    cout << "找不到适合的空闲分区" << endl;
    return 0;
  }
  return pid;
}

int freeMemory(int pid) {
  int id = 0;
  int address, length;
  int i = 0;
  int top = -1, bottom = -1;

  while( id < N && usedTable[id].flag != pid) {
    id++;
  }

  if (id < N) {
    address = usedTable[id].add;
    length = usedTable[id].len;
    usedTable[id].flag = 0;
  } else {
    cout << "该进程不存在" << endl;
  }

  // 修改空闲分配表
  while(!(i >= M || (top != -1 && bottom != -1))) {
    if (freeTable[i].flag == 1) {
      if (freeTable[i].add + freeTable[i].len == address) {
        top = i;
      }
      if (address + length ==  freeTable[i].add ) {
        bottom = i;
      }
    }
    i++;
  }

  if (top != -1) {
    if (bottom != -1) { // 上下都有空闲区
      freeTable[top].len += freeTable[bottom].len + length;
      freeTable[bottom].flag = 0;
    } else {
      freeTable[top].len += length;
    }
  } else if (bottom != -1) {
    freeTable[bottom].len += length;
    freeTable[bottom].add = address;
  } else {
    int j = 0;
    // 找到一个空闲分区
    while (freeTable[j].flag != 0) {
      j++;
    }
    if (j <  M) {
      freeTable[j].add = address;
      freeTable[j].len = length;
      freeTable[j].flag = 1;
    } else { // 回收失败
      usedTable[id].flag = pid;
      cout << "空闲区已满，回收失败" << endl;
      return -1;
    }
  }
  return pid;
}

bool compareAddress(Table a, Table b) {
  return a.add < b.add;
}

void show() {
  sort(freeTable.begin(), freeTable.end(), compareAddress);
  cout << "内存分配情况：" << endl;
  for (int i = 0; i < usedTable.size(); i++) {
    if (usedTable[i].flag != 0) {
      cout << "\t地址：" << setw(4) << usedTable[i].add << "  进程号:" << setw(3) << usedTable[i].flag << "  进程空间大小：" << setw(4) <<  usedTable[i].len << endl;
    }
  }
  cout << "空闲区：" << endl;
  for (int j = 0; j < freeTable.size(); j++) {
    if (freeTable[j].flag != 0) {
      cout << "\t地址：" << setw(4) << freeTable[j].add <<  "  进程空间大小：" << setw(4) <<  freeTable[j].len << endl;
    }
  }
}

int main() {
  int op; // 操作
  bool end = false;
  int pid, needlen;
  initTable();

  while(!end) {
    cout << "请输入操作：" << endl;
    cout << "（1）使用【最佳适配算法】内存申请空间 （2）使用【最差适配算法】内存申请空间 （3）使用【首次适配算法】内存申请空间" << endl;
    cout << "（4）内存释放空间 (0)退出程序" << endl;
    cin >> op;
    switch(op) {
      case 0: {
        end = true;
        break;
      }
      case 1: {
        cout << "请输入进程名和所需内存: " << endl;
        cin >> pid >> needlen;
        BestFit(pid, needlen);
        show();
        break;
      }
      case 2: {
        cout << "请输入进程名和所需内存: " << endl;
        cin >> pid >> needlen;
        WorstFit(pid, needlen);
        show();
        break;
      }
      case 3: {
        cout << "请输入进程名和所需内存: " << endl;
        cin >> pid >> needlen;
        FirstFit(pid, needlen);
        show();
        break;
      }
      case 4: {
        cout << "请输入进程号 " << endl;
        cin >> pid;
        freeMemory(pid);
        show();
        break;
      }
      default: {
        show();
      }
    }
  }
  return 0;
}