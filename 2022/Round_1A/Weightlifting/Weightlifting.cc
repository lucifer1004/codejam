#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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
 public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int E, W;
    read(E), read(W);
    vector<vector<int>> X(E + 2, vector<int>(W));
    for (int i = 1; i <= E; ++i)
      for (int j = 0; j < W; ++j) read(X[i][j]);

    E += 2;
    vector<vector<vector<int>>> H(E, vector<vector<int>>(E, vector<int>(W)));
    for (int i = 0; i < W; ++i) {
      for (int l = 0; l < E; ++l) {
        int lo = INT_MAX;
        for (int r = l; r < E; ++r) {
          lo = min(lo, X[r][i]);
          H[l][r][i] = lo;
        }
      }
    }

    vector<vector<int>> dp(E, vector<int>(E));

    for (int len = 2; len <= E; ++len) {
      for (int l = 0; l + len - 1 < E; ++l) {
        int r = l + len - 1;
        dp[l][r] = INT_MAX;
        for (int k = l; k < r; ++k) {
          int curr = dp[l][k] + dp[k + 1][r];
          for (int i = 0; i < W; ++i)
            curr += abs(H[l][r][i] - H[l][k][i]) +
                    abs(H[k + 1][r][i] - H[l][k][i]) +
                    abs(H[l][r][i] - H[k + 1][r][i]);
          dp[l][r] = min(dp[l][r], curr);
        }
      }
    }

    printf("%d\n", dp[0][E - 1]);
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