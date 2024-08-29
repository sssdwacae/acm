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

int n, m, t, k;
typedef struct {
  int x, y;
} info;

void solve() {
  cin >> n >> k;
  vector<info> a(n);
  unordered_map<int, vector<int>> mp[2];

  for (info &it : a) {
    cin >> it.x >> it.y;
    mp[0][it.x].push_back(it.x), mp[1][it.y].push_back(it.y);
  }

  int f = 1;
  for (int i = 0; i < 2; ++i)
    if (mp[i].size() == k) {
      for (const auto &[k, v] : mp[i]) {
        if (v.size() < 2) {
          f = 0;
          break;
        }
      }
      if (f) {
        for (const auto &[k, v] : mp[i]) {
          cout << v.size() << ' ';
          for (const int &it : v)
            cout << it + 1 << ' ';
          cout << endl;
        }
        return;
      }
    }

  for (int i = 1; i < n; ++i) {
    // cerr << "Compare " << a[0].x << ' ' << a[0].y << " with " << a[i].x << ' '
         // << a[i].y << endl;
    if (a[i].x == a[0].x || a[i].y == a[0].y)
      continue;
    unordered_map<double, vector<int>> mp;
    double k = 1.0 * (a[i].y - a[0].y) / (a[i].x - a[0].x);
    mp[a[0].y - a[0].x * k].push_back(0);
    mp[a[0].y - a[0].x * k].push_back(i);
    // debug(k);
    for (int j = 1; j < n; ++j) {
      if (j == i)
        continue;
      double tmp = a[j].y - a[j].x * k;
      // cerr << a[j].x << ' ' << a[j].y << ' ';
      // debug(tmp);
      // cerr << endl;
      if (mp.find(tmp) == mp.end())
        mp[tmp] = vector<int>(1, j);
      else
        mp[tmp].push_back(j);
      if (mp.size() > k)
        break;
    }

    // for (const auto &[k, v] : mp) {
    //   cerr << k << ": " << v.size() << endl;
    //   for (const int &it : v)
    //     cerr << it << ' ';
    //   cerr << endl;
    // }

    if (mp.size() == k) {
      for (const auto &[k, v] : mp) {
        if (v.size() < 2) {
          f = 0;
          break;
        }
      }
      if (f) {
        for (const auto &[k, v] : mp) {
          cout << v.size() << ' ';
          for (const int &it : v)
            cout << it + 1 << ' ';
          cout << endl;
        }
        return;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cerr.tie(0);

  solve();
}
