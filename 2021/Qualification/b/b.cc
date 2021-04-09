#include <cstdio>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int x, y;
    read(x), read(y);
    string s;
    cin >> s;
    int n = s.size();
    int c = INF, j = INF;
    if (s[0] != 'C')
      j = 0;
    if (s[0] != 'J')
      c = 0;
    for (int i = 1; i < n; i++) {
      int nj = INF, nc = INF;
      if (s[i] != 'C') {
        if (j != INF)
          nj = j;
        if (c != INF)
          nj = min(nj, c + x);
      }
      if (s[i] != 'J') {
        if (c != INF)
          nc = c;
        if (j != INF)
          nc = min(nc, j + y);
      }
      j = nj, c = nc;
    }
    printf("%d\n", min(j, c));
  }
};

int main() {
  int t;
  read(t);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}