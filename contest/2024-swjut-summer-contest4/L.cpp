#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int cnt=0;

void solve()
{
    double n,m;
    cin>>n>>m;
    if(n>=2)
        n=1.0/2;
    else
        n=1;
    if(m>=2)
        m=1.0*(m+1)/(2*m);
    else
        m=1;
    printf("Case #%d: %.06lf %.06lf\n",++cnt,n,m);
    return;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}