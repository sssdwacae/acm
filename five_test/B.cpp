#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5 + 5;
#define ll long long
#define mp make_pair
int n, S;
int c[N], y[N];
int ans = 0;

void solve()
{
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> y[i];
    }
    // cout<<n<<endl;
    for (int i = n; i >= 1; i--)
    { // 第i天的由第j天生产
        int mn = 0x3f3f3f3f;
        int pos = 0;
        for (int j = 1; j <= i; j++)
        {
            int temp = c[j] * y[i] + S * (i - j) * y[i]; //*y[i];
            if (temp < mn)
            {
                mn = temp;
                pos = j;
            }
        }
        ans += mn;
        // if(i==1)
        // cout<<mn<<' '<<pos<<' '<<endl;
    }
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
    T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}