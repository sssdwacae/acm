#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define valid(x, y) 0 <= x &&x < n && 0 <= y &&y < m

#ifdef DEBUG
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

using pii = pair<int, int>;

int n, m, t;

void solve() {
  cin >> n;
  vector<int> a(n), c(n);
  for (int &it : a)
    cin >> it;
  int c1 = 0, c0 = 0, mn = LONG_LONG_MAX;
  vector<int> a1, a0;
  a1.reserve(n), a0.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    if (c[i]) {
      ++c1, a1.push_back(a[i]);
    } else {
      ++c0, a0.push_back(a[i]);
    }
    if (c1 == c0) {
      sort(a1.begin(), a1.end());
      sort(a0.begin(), a0.end(), greater<int>());
      for (int i = 0; i < (int)a1.size(); ++i)
        mn = min(mn, a1[i] + a0[i]);
      c1 = c0 = 0;
      a1.clear(), a0.clear();
    }
  }
  sort(a1.begin(), a1.end());
  sort(a0.begin(), a0.end(), greater<int>());
  int l = a1.size() - 1, r = 0;
  while (l >= 0 && r < (int)a0.size())
    mn = min(mn, a1[l--] + a0[r++]);
  cout << mn << endl;
}

signed main() {
    freopen("in.txt","r",stdin);
freopen("solout.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cerr.tie(0);

  solve();
}    