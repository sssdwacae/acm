#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    s=' '+s;
    unordered_map<pair<int, int>, int, pair_hash> cnt;
    if(x==0&&y==0){
        cout<<(1+n)*n/2;
        return;
    }
    int nx=0,ny=0,ans=0;
    cnt[mp(nx,ny)]++;
    for(int i=1;i<=n;i++){
        switch(s[i]){
            case 'A':
                nx--;
                break;
            case 'W':
                ny++;
                break;
            case 'D':
                nx++;
                break;
            case 'S':
                ny--;
                break;
        }
        //now-pre=x
        if(cnt.find(mp(nx-x,ny-y))!=cnt.end()){
            // cout<<cnt[mp(x-nx,y-ny)]<<' '<<i<<' '<<cnt[mp(nx-x,ny-y)]*(n-i+1)<<endl;
            ans+=cnt[mp(nx-x,ny-y)]*(n-i+1);
            cnt[mp(nx-x,ny-y)]=0;
        }
        // cout<<nx<<' '<<ny<<endl;
        cnt[mp(nx,ny)]++;
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