#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Cell {
  int skill;
  int left = -1, right = -1, up = -1, down = -1;
  int nl = -1, nr = -1, nu = -1, nd = -1;
  bool inqueue = false, exist = true;

  explicit Cell(int skill) : skill(skill) {}
};

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int r, c;
    cin >> r >> c;
    vector<vector<Cell>> cells(r);
    ll sum = 0, ans = 0;
    queue<pair<pii, int>> q;
    int round = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        int skill;
        cin >> skill;
        Cell cell(skill);
        if (j > 0)
          cell.left = cell.nl = j - 1;
        if (j < c - 1)
          cell.right = cell.nr = j + 1;
        if (i > 0)
          cell.up = cell.nu = i - 1;
        if (i < r - 1)
          cell.down = cell.nd = i + 1;
        sum += skill;
        cells[i].emplace_back(cell);
        q.push({{i, j}, 1});
      }

    bool this_round_counts = true;
    vector<pii> changed;
    while (!q.empty()) {
      auto front = q.front();
      q.pop();
      pii coordinate = front.first;
      int i = coordinate.first, j = coordinate.second;
      Cell &cell = cells[i][j];
      if (!cell.exist)
        continue;
      int current_round = front.second;
      if (current_round > round) {
        if (this_round_counts) {
          ans += sum;
          this_round_counts = false;
        }
        for (pii p : changed) {
          int pi = p.first, pj = p.second;
          Cell &pcell = cells[pi][pj];
          pcell.inqueue = false;
          pcell.left = pcell.nl;
          pcell.right = pcell.nr;
          pcell.up = pcell.nu;
          pcell.down = pcell.nd;
        }
        changed.clear();
        round = current_round;
      }
      int s = 0, num = 0;
      if (cell.left != -1) {
        num++;
        s += cells[i][cell.left].skill;
      }
      if (cell.right != -1) {
        num++;
        s += cells[i][cell.right].skill;
      }
      if (cell.up != -1) {
        num++;
        s += cells[cell.up][j].skill;
      }
      if (cell.down != -1) {
        num++;
        s += cells[cell.down][j].skill;
      }
      if (cell.skill * num < s) {
        cell.exist = false;
        this_round_counts = true;
        sum -= cell.skill;
        if (cell.nl != -1) {
          cells[i][cell.nl].nr = cell.nr;
          if (!cells[i][cell.nl].inqueue) {
            cells[i][cell.nl].inqueue = true;
            q.push({{i, cell.nl}, current_round + 1});
            changed.emplace_back(i, cell.nl);
          }
        }
        if (cell.nr != -1) {
          cells[i][cell.nr].nl = cell.nl;
          if (!cells[i][cell.nr].inqueue) {
            cells[i][cell.nr].inqueue = true;
            q.push({{i, cell.nr}, current_round + 1});
            changed.emplace_back(i, cell.nr);
          }
        }
        if (cell.nu != -1) {
          cells[cell.nu][j].nd = cell.nd;
          if (!cells[cell.nu][j].inqueue) {
            cells[cell.nu][j].inqueue = true;
            q.push({{cell.nu, j}, current_round + 1});
            changed.emplace_back(cell.nu, j);
          }
        }
        if (cell.nd != -1) {
          cells[cell.nd][j].nu = cell.nu;
          if (!cells[cell.nd][j].inqueue) {
            cells[cell.nd][j].inqueue = true;
            q.push({{cell.nd, j}, current_round + 1});
            changed.emplace_back(cell.nd, j);
          }
        }
      }
    }

    if (this_round_counts)
      ans += sum;
    cout << "Case #" << case_num << ": " << ans << endl;
  }
}