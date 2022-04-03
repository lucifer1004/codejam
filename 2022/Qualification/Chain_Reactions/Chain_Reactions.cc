#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
using ll = long long;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  int n;
  vector<vector<int>> adj;
  vector<int> f, p;

  pair<ll, int> dfs(int u) {
    if (adj[u].empty()) return {f[u], f[u]};

    ll pts = 0;
    int min_max = INF;
    for (int v : adj[u]) {
      auto [pv, mmv] = dfs(v);
      pts += pv;
      min_max = min(min_max, mmv);
    }

    pts += f[u] - min(f[u], min_max);
    return {pts, max(f[u], min_max)};
  }

 public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    read(n);
    f = vector<int>(n + 1);
    p = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; ++i) read(f[i]);
    for (int i = 1; i <= n; ++i) {
      read(p[i]);
      adj[p[i]].emplace_back(i);
    }

    auto [pts, min_max] = dfs(0);
    printf("%lld\n", dfs(0).first);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}