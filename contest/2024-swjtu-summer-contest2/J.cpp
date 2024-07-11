#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n,m;
    cin>>n>>m;
    if(m==n){
        cout<<0<<endl;
        return;
    }
    else if(m<n){
        cout<<fabs(m-n)<<endl;
        return;
    }
    //m>n
    int ans1=m%n;//只补
    
    //n 5 m 8
    int ans2=n-m%n;
    
    for(int i=ans2;i<n;i++)
        if(m%i==0)
            ans2=i;
    //只杀

    int ans=min(ans2,ans1);
    if(ans>1e5){
        cout<<ans<<endl;
        return;
    }
    int result=ans;
    for(int i=n-ans;i<=n+ans;i++)
        for(int j=m-ans;j<=m+ans;j++)
            if(j%i==0){
                int temp=fabs(i-n)+fabs(j-m);
                ans=min(ans,temp);
            }
    cout<<ans<<endl;
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