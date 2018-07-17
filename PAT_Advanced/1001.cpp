#include <cstdio>
#include <string>
using namespace std;

int main()
{
  long long int n, m, k, p;
  scanf("%lld %lld", &n, &m);

  k = n + m;
  if (k < 0) {
    printf("-");
  }
  p = abs(k);
  int i, j;
  string s = to_string(p);
  for (j = 0; j < s.length(); j++) {
    printf("%c", s[j]);
    if (s.length() > 3) {
      i = s.length() % 3;
      if ((j == i - 1 || ((j - i + 1) % 3 == 0)) && j != s.length() - 1) {
        printf(",");
      }
    }
  }
  return 0;
}