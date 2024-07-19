#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=5e3+5;
#define ll long long
#define mp make_pair

int a[N],b[N],dp[N][N];

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    //dp  1-n 选了j段
    for(int i=1;i<=n;i++){
        
    }
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