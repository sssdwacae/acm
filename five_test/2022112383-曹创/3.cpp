#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define int long long
#define mp make_pair

int a[N];
bool check[N];
int cnt[N];

int n, ans;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<pair<int, int>> v;

void dfs(int pos, int sum)
{
    if (pos == v.size())
    {
        ans = max(sum, ans);
        return;
    }
    // 不选

    if (check[v[pos].first] == 0) // 可选
    {
        // cout<<check[2]<<' '<<check[3]<<' '<<check[4]<<endl;
        check[v[pos].first + 1] = 1;
        check[v[pos].first - 1] = 1;
        dfs(pos + 1, sum + v[pos].second);
        check[v[pos].first + 1] = 0;
        check[v[pos].first - 1] = 0;
    }
    dfs(pos + 1, sum);

    return;
}
void solve()
{
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    for (int i = 1; i <= mx; i++)
    {
        if (cnt[i] != 0)
            v.push_back(mp(i, i * cnt[i]));
    }
    // sort(v.begin(), v.end(), cmp);
    //  for(int i=0;i<v.size();i++)
    //      cout<<v[i].first<<' '<<v[i].second<<endl;
    dfs(0, 0);
    cout << ans;
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