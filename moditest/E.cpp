#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<int> d(n + 1, INF);
    vector<int> cnt(n + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        if (pq.top().first > d[u])
        {
            pq.pop();
            continue;
        }
        pq.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (d[u] + 1 < d[v])
            {
                d[v] = d[u] + 1;
                cnt[v] = cnt[u];
                pq.push(mp(d[v], v));
            }
            else if (d[u] + 1 == d[v])
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
        }
    }

    if (d[n] == INF)
        cout << 0;
    else
        cout << cnt[n];
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    // cin>>T;
    T = 1;
    while (T--)
        solve();
    return 0;
}