#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n,d;
    cin>>n>>d;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin()+1,a.begin()+1+n);
    int ans=0;
    int nd=a[1];
    for(int i=2;i<=n-1;i++){
        if(a[i+1]-nd<=d)
            ans++;
        else
            nd=a[i];
    }
    cout<<ans<<endl;
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