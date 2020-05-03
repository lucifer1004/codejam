#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

struct Fraction {
  ll a, b;

  Fraction(ll x, ll y) {
    ll g = gcd(x, y);
    a = x / g;
    b = y / g;
  }

  bool operator<(const Fraction &that) const { return a * that.b < b * that.a; }
};

ll divide(ll x, Fraction y) { return x * y.b / y.a; }

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a.begin(), a.end());
    map<Fraction, vector<int>> dict;
    for (ll i : a) {
      for (int j = 1; j <= d; ++j) {
        Fraction f(i, j);
        dict[f].emplace_back(j);
      }
    }
    vector<Fraction> v;
    v.reserve(dict.size());
    for (const auto &p : dict)
      v.emplace_back(p.first);
    int l = 0, r = v.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      ll can = 0;
      for (ll i : a)
        can += divide(i, v[mid]);
      if (can >= d)
        l = mid + 1;
      else
        r = mid - 1;
    }
    int ans = d - 1;
    for (int i = 0; i <= r; ++i) {
      sort(dict[v[i]].begin(), dict[v[i]].end());
      int sum = 0, slices = 0;
      for (int j : dict[v[i]]) {
        if (sum + j <= d) {
          sum += j;
          slices += j - 1;
        } else
          break;
      }
      ans = min(ans, slices + d - sum);
    }
    cout << "Case #" << case_num << ": " << ans << endl;
  }
}