#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 505
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int dx[3] = {1, 0, 1}, dy[3] = {0, 1, 1};
vector<vector<ll>> a;
vector<pii> path, ans;
bool found;

void dfs(int target) {
  if (found || path.size() > 500)
    return;
  if (target == 0) {
    ans = path;
    found = true;
    return;
  }
  pii current = path.back();
  int i = current.first, j = current.second;
  if (i == j) {
    int steps = path.size();
    int rest = 500 - steps;
    if (rest >= target) {
      for (int k = 1; k <= target; ++k)
        path.emplace_back(i + k, i + k);
      ans = path;
      found = true;
      return;
    }
  } else if (j == 1) {
    int steps = path.size();
    int rest = 500 - steps;
    if (rest >= target) {
      for (int k = 1; k <= target; ++k)
        path.emplace_back(i + k, 1);
      ans = path;
      found = true;
      return;
    }
  }
  vector<pair<int, pii>> nxt;
  for (int k = 0; k < 3; ++k) {
    int ni = i + dy[k], nj = j + dx[k];
    if (ni >= 500 || nj >= 500 || nj > ni || a[ni][nj] == 0 ||
        a[ni][nj] > target)
      continue;
    nxt.push_back({target - a[ni][nj], {ni, nj}});
  }
  sort(nxt.begin(), nxt.end());
  for (auto p : nxt) {
    pii coordinate = p.second;
    int ni = coordinate.first, nj = coordinate.second;
    path.emplace_back(ni, nj);
    dfs(p.first);
    if (found)
      return;
    path.pop_back();
  }
}

int main() {
  int t;
  cin >> t;
  a.assign(MAXN, vector<ll>(MAXN, 0));
  for (int i = 1; i <= 500; ++i) {
    a[i][1] = 1;
    a[i][i] = 1;
    for (int j = 2; j < i; ++j) {
      if (!a[i - 1][j - 1] || !a[i - 1][j])
        continue;
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
      if (a[i][j] > INF)
        a[i][j] = 0;
    }
  }

  for (int case_num = 1; case_num <= t; ++case_num) {
    found = false;
    int n;
    cin >> n;
    ans.clear();
    cout << "Case #" << case_num << ":" << endl;
    path = {{1, 1}};
    dfs(n - 1);
    for (pii p : ans)
      cout << p.first << " " << p.second << endl;
  }
}