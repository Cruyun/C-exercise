// 俄式乘法
#include <iostream>
using namespace std;

int main()
{
	int n, m;
  cin >> n >> m;
  int res = 0;

  while (n >= 1) {
    if (n % 2 == 0) {
      n = n >> 1;
      m = m << 1;
    } else {
      res += m;
      n = (n - 1) / 2;
      m = m << 1;
    }
  }
  cout << res;
	return 0;
}

