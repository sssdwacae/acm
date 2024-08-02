#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=n;j++)
        cin>>b[j];
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>b[i])
            ans++;
        else if(a[i]==b[i])
            cnt++;
    }
    ans+=(cnt+1)/2;
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