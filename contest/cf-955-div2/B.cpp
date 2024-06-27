#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    ll x,y,k,i=0;
    cin>>x>>y>>k;
    while(i+y-x%y<=k){
        i+=y-x%y;
        // cout<<endl<<endl;
        // cout<<x<<' '<<y<<endl;
        // cout<<'?'<<y-x%y<<endl;
        x+=y-x%y;
        // cout<<x<<' '<<(double)x*1.0/y<<endl<<endl;

        while(x%y==0)
            x/=y;
        if(x==1){
            // cout<<'&'<<(x+k-i)%(y-1)<<' '<<x+k<<' '<<i<<' '<<y<<' '<<k-i<<endl;

            x=(x+k-i)%(y-1);
            if(x==0)
                x=y-1;
            i=k;
            if(y==2)
                x=1;
        }
    }
    cout<<x+k-i;
    cout<<endl;
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