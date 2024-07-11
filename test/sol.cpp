#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
using pii = pair<int, int>;

int n, m, t;
vector<int> ll, rr;
vector<string> l, r;

void solve() {
  cin >> n;
  ll = vector<int>(n), rr = vector<int>(n);
  l = vector<string>(n), r = vector<string>(n);
  for (int i = 0; i < n; ++i)
    cin >> ll[i] >> rr[i];

  for (int i = 0; i < n; ++i)
    for (int j = 29; j >= 0; --j) {
      l[i] += (1 << j) & ll[i] ? '1' : '0';
      r[i] += (1 << j) & rr[i] ? '1' : '0';
    }

  // for (int i = 0; i < n; ++i) {
  //   cerr << l[i] << endl;
  //   cerr << r[i] << endl;
  // }

  int flag, term = 1 << 29;
  int res = 0;

  for (int i = 0; i < 30; ++i) {
    flag = 1;

    for (int k = 0; k < n; ++k)
      if (r[k][i] == '0') {
        flag = 0;
        break;
 }

    if (flag) {
      res += term;
      cerr << "add: " << term << endl;
    } else {
      for (int x = 0; x < n; ++x) {
        if (r[x][i] == '1') {
          for (int k = i; k < 30; ++k) {
            if (r[x][k] == '1' && l[x][k] == '0') {
              while (k < 30)
                r[x][k++] = '1';
            }
          }
        }
      }
    }

    term >>= 1;
  }

  cout << res << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
    freopen("in.txt","r",stdin);
    freopen("solout.txt","w",stdout);
  cin >> t;
  while (t--)
    solve();
}

	