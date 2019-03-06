/* 硬币问题 
输入V总价值 2:n2,3:n3,5:n5分别代表有多少个二元、三元、五元硬币，
求出最少数量的硬币能凑到总价值V
动态规划问题
*/

int coins(int n2, int n3, int n5, int v) {
  int v[3] = {2, 3, 5};
  int n = 3; // 3种硬币
  int i, j;

  vetor<int> min = {0};
  min[0] = 0;

  vector<int> cnt;
  cnt.push(n2);
  cnt.push(n3);
  cnt.psuh(n5);

  for (i = 0; i < v; i++) {
    for (j = 0; j < 2; j++) {
      int tmp = cnt[j] - 1;
      if (tmp >= 0 && v[j] < i && min[i - v[j]] + 1 < min[i]) {
        min[i] = min[i - v[j]] + 1;
        cnt[j]--;
      }
    }
  }
  return min.size();
}