#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 2e5 + 5;
#define int long long
#define ll long long 
#define mp make_pair
#define MOD 998244353

int pw[N], b[N];
int a[N];

// 快速幂计算 base^exp % mod
ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 计算模逆元
ll modInverse(ll x, ll mod) {
    return modExp(x, mod - 2, mod);
}

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = (ans + a[i] * a[i]) % MOD;
    }
    sort(a + 1, a + 1 + n);

    pw[1] = 1;
    for (int i = 2; i <= n; i++)
        pw[i] = pw[i - 1] * 2 % MOD;
    // pw[i] = 2^(i-1)

    ll temp = 0;
    for (int i = 2; i <= n; i++) {
        temp = (temp + (pw[i - 1] * a[i])  % MOD) % MOD;
    }

    // cout<<temp<<endl;
    ans = (ans + temp*a[1]) % MOD;

    for (int i = 2; i < n; i++) {
        // cout<<temp<<endl;
        temp = (temp - a[i] + MOD) % MOD;
        temp = (temp * modInverse(2, MOD)) % MOD;
        ans = (ans + temp * a[i]) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return;
}
void TLE();
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    // cin >> T;

    //TLE();
    //return 0;
    

    
    T = 1;
    while (T--)
        solve();
    return 0;
}


void TLE()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    pw[1]=1;
    for(int i=2;i<=n;i++)
        pw[i]=pw[i-1]*2%MOD;
    //pw i = 2^(i-1)
    int temp=0;
    for(int i=1;i<=n;i++){
        // cout<<ans<<endl;
        for(int j=i;j<=n;j++){
            if(i==j)
                ans=((a[i]*a[i])%MOD+ans)%MOD;
            else
                ans=(((a[i]*a[j])%MOD*pw[j-i])%MOD+ans)%MOD;
        }
    }
    cout<<(ans+MOD)%MOD;
    return;
}