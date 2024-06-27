#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(y1<=x1&&y2>=x2||x1<=y1&&x2>=y2)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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