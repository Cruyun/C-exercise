#include <iostream>
#include <vector>
#include <queue>
#define SIZE 3 // 假设有5个页面
using namespace std;

typedef struct Page {
  int page;
  int cnt; // 访问次数
} Page;

void FIFO(vector<int> list, int n);
void LRU(vector<int> list, int n);
void show(vector<int> list);


void FIFO(vector<int> list, int n) {
  vector<int> q; // 页面队列
  int fail = 0;
  int i;

  for (i = 0; i < n; i++) {
    bool flag = false; // 页面是否已在缓存中

    for (int j = 0; j < q.size(); j++) {
      if (q[j] == list[i]) {
        flag = true;
      }
      if (flag) {
        break;
      }
    }

    if (flag) {
      cout << "访问" << list[i] << "页面成功" << endl;
      // show(q);
    } else {
      cout << "访问" << list[i] << "页面失败" << endl;
      if (q.size() >= SIZE) {
        cout << "淘汰" << q.front() << "页面" << endl;
        q.erase(q.begin());
      }
      q.push_back(list[i]);
      // show(q);
      fail++;
    }
  }
  cout << "缺页总次数为:" << fail << " " << "缺页中断率为：" << float(fail) / float(n) << endl; 
}
bool cmp(Page a, Page b) {
  return a.cnt < b.cnt;
}

void LRU(vector<int> list, int n) {
  vector<Page> q;
  int i;
  int fail = 0;

  for (i = 0; i < n; i++) {
    bool flag = false; // 页面是否已在缓存中

    if (!q.empty()) {
      for (int j = 0; j < q.size(); j++) {
        if (q[j].page == list[i]) {
          flag = true;
          q[j].cnt++;
          sort(q.begin(), q.end(), cmp);
        }
        if (flag) {
          break;
        }
      }
    }
    
    if (flag) {
      cout << "访问" << list[i] << "页面成功" << endl;
    } else {
      cout << "访问" << list[i] << "页面失败" << endl;
      if (q.size() >= SIZE) {
        cout << "淘汰" << q.front().page << "页面" << endl;
        q.erase(q.begin());
      }
      Page p;
      p.page = list[i];
      p.cnt = 1;

      q.push_back(p);
      fail++;
      sort(q.begin(), q.end(), cmp);
    }
  }
  cout << "缺页总次数为:" << fail << " " << "缺页中断率为：" << float(fail) / float(n) << endl; 
}
void show(vector<int> list) {
  cout << "缓存序列为： ";
  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
  }
  cout << endl;
}

int main() {
  cout << "请输入页面请求序列长度:" ;
  int n;
  cin >> n;
  vector<int> input(n);
  cout << "请输入页面请求序列:" ;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  FIFO(input, n);
  cout << "---------------------------" << endl;
  LRU(input, n);

  return 0;
}