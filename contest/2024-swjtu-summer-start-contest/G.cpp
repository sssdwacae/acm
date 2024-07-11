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
    int ans=0;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i)
            v[j]++;
        ans+=i*v[i];
    }
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