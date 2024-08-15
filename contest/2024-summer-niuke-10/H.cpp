#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

const int MOD=998244353;

int modpower(int base, int exp)
{
    int result=1;
    while(exp>0){
        if(exp%2==1)
            result=(result*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return result;
}

int mod(int y)
{
    return modpower(y,MOD-2);
}

void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<a*mod(a+b)%MOD<<' '<<b*mod(a+b)%MOD<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}