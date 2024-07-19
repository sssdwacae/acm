#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// const int N = 1e8 + 5;
#define int long long
#define mp make_pair
const int MOD = 1e9 + 7;

// int ans[N];

long long pow_m(long long a, long long n)
{
    long long ret = 1;
    long long tmp = a % MOD;
    while (n)
    {
        if (n & 1)
            ret = (ret * tmp) % MOD;
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    return ret;
}
// 计算
long long inv(long long a) // mod为素数
{
    return pow_m(a, MOD - 2);
}
void solve()
{
    // 2*n^2-n求和
    int n;
    cin >> n;
    int num = 0;
    num += (2022 * n % MOD * (n + 1) % MOD * (2 * n + 1)%MOD*inv(3) % MOD);
        num -= (((n + 1) * n %MOD *inv(2) %MOD) % MOD * 2022) % MOD;
    // num+=ans[n];
    num = (MOD + num) % MOD;
    cout << num << endl;
    // int temp=0;
    // for(int i=1;i<=10;i++){
    //     cout<<i<<":";
    //     temp+=i*i;
    //     cout<<temp<<endl;
    // }
    return;
}

// void init()
// {
//     for(int i=1;i<=1e7;i++){
//         ans[i]=ans[i-1]+((i*i)%MOD*2022)%MOD;
//         ans[i]%=MOD;
//     }
// }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    // init();
    while (T--)
        solve();
    return 0;
}