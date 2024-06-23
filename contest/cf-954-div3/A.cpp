#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int A=min(a,min(c,b));
    int C=max(a,max(c,b));
    cout<<fabs(A-C)<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}