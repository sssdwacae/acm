#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int l,n;
int a[N];
void solve()
{   
    cin>>l>>n;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        for(int j=x;j<=y;j++)
            a[j]++;
    }
    int ans=0;
    for(int i=0;i<=l;i++)
        if(!a[i])
            ans++;
    cout<<ans;
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