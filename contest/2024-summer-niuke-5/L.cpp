#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define int long long
#define mp make_pair

const int MOD = 998244353;

int qpow(int base, int exp)
{
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return ans;
}

void solve()
{
    // cout<<98*100*100*100%MOD<<endl;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1;
    int sum = 0, cnt = 0;
    int pos = n;
    while (pos)
    {
        if (sum == 0)
        {
            sum += a[pos];
            pos--;
            cnt++;
        }
        else if (sum / cnt >= a[pos])
        {
            sum += a[pos];
            pos--;
            cnt++;
        }
        else
        {
            if (sum % cnt != 0)
                ans = ans * qpow(sum / cnt, cnt - sum % cnt) % MOD * qpow(sum / cnt + 1, sum % cnt) % MOD;
            else
                ans = ans * qpow(sum / cnt, cnt) % MOD;
            // cout<<"?"<<ans<<endl;
            sum = a[pos];
            pos--;
            cnt = 1;
        }
    }
    // cout<<"sum:"<<sum<<"  cnt:"<<cnt<<"ans"<<ans<<endl;
    if (sum % cnt != 0)
        ans = ans * qpow(sum / cnt, cnt - sum % cnt) % MOD * qpow(sum / cnt + 1, sum % cnt) % MOD;
    else
        ans = ans * qpow(sum / cnt, cnt) % MOD;
    ans %= MOD;
    cout << ans << endl;
    // cout<<n<<' '<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}