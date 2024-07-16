#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<pair<int,int> >a,b;
    for(int i=1,q,w;i<=x;i++){
        cin>>q>>w;
        a.push_back(mp(q,w));
    }
    for(int i=1,q,w;i<=y;i++){
        cin>>q>>w;
        b.push_back(mp(q,w));
    }
    int ans=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i].second<b[j].first||b[j].second<a[i].first)
                continue;
            // cout<<a[i].first<<' '<<a[i].second<<' '<<b[j].first<<' '<<b[j].second<<endl;
            int temp=min(a[i].second,b[j].second)-max(a[i].first,b[j].first)+1;
            // cout<<temp<<endl;
            if(temp<m)
                continue;
            ans+=temp-m+1;
            // cout<<"ans:"<<ans<<endl;
        }
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