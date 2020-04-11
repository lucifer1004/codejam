#include <bitset>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int n;
    cin >> n;
    cout << "Case #" << case_num << ":" << endl;
    if (n <= 30) {
      for (int i = 1; i <= n; ++i)
        cout << i << " 1" << endl;
    } else {
      n -= 30;
      int extra = 30;
      bool left = true;
      bitset<32> bs(n);
      for (int i = 0; i < 32; ++i) {
        if (bs[i]) {
          if (left) {
            for (int j = 1; j <= i + 1; ++j)
              cout << i + 1 << " " << j << endl;
          } else {
            for (int j = i + 1; j >= 1; --j)
              cout << i + 1 << " " << j << endl;
          }
          left = !left;
        } else if (extra--) {
          if (left)
            cout << i + 1 << " " << 1 << endl;
          else
            cout << i + 1 << " " << i + 1 << endl;
        }
      }
      for (int i = 1; i <= extra; ++i)
        cout << i + 32 << " " << (left ? 1 : i + 32) << endl;
    }
  }
}