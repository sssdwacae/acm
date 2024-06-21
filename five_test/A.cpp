#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair
int a[N];
int sum = -1;
int n;
int C1, C2;

void dfs(int c1, int c2, int pos)
{
    if (pos == n + 1)
    {
        sum = max(sum, max(C1 - c1, C2 - c2));
        return;
    }
    if (c1 >= a[pos])
        dfs(c1 - a[pos], c2, pos + 1);
    if (c2 >= a[pos])
        dfs(c1, c2 - a[pos], pos + 1);
    return;
}

void solve()
{

    cin >> C1 >> C2;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(C1, C2, 1);
    if (sum != -1)
        cout << sum;
    else
        cout << "impossible";
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << "2022112383\n";
    int T;
    // cin>>T;
    T = 1;
    while (T--)
        solve();
    return 0;
}