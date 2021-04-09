#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int N = 100, M = 10000;

int t, p;

int main() {
  cin >> t >> p;
  for (int case_num = 1; case_num <= t; ++case_num) {
    cout << "Case #" << case_num << ": ";
    vector<string> v(N);
    vector<int> cnt(N);
    for (int i = 0; i < N; ++i) {
      cin >> v[i];
      for (char c : v[i])
        cnt[i] += c == '1';
    }

    vector<double> difficulty(M, 1.0);
    vector<double> skill(N, 0.0);
    for (int it = 0; it < 10; ++it) {
      double skill_max = 0.0;
      for (int i = 0; i < N; ++i) {
        skill[i] = 0.0;
        for (int j = 0; j < M; ++j)
          if (v[i][j] == '1')
            skill[i] += difficulty[j];
        skill_max = max(skill_max, skill[i]);
      }
      for (int i = 0; i < N; ++i)
        skill[i] /= skill_max;

      double difficulty_max = 0.0;
      for (int i = 0; i < M; ++i) {
        difficulty[i] = 0.0;
        for (int j = 0; j < N; ++j) {
          if (v[j][i] == '0')
            difficulty[i] += skill[j];
        }
        difficulty_max = max(difficulty_max, difficulty[i]);
      }
      for (int i = 0; i < M; ++i)
        difficulty[i] /= difficulty_max;
    }

    vector<double> strange(N, 0.0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (v[i][j] == '0')
          strange[i] += max(0.0, skill[i] - difficulty[j]);
      }
    }

    int hi = 0;
    for (int j = 1; j < N; ++j)
      if (strange[j] > strange[hi] && cnt[j] > M / 2)
        hi = j;

    cout << hi + 1 << endl;
  }
}