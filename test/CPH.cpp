#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


int fun(int x){
    static int a=3;
    a+=x;
    return a;
}

void solve()
{
    int k=2,m=1,n;
    n=fun(k);
    n=fun(m);
    cout<<n;
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