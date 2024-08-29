#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair
#define L a[i].first
#define R a[i].second

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first<b.first;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>L>>R;
        L-=i;R-=i;
    } 
    sort(a.begin()+1,a.begin()+1+n,cmp);
    // for(int i=1;i<=n;i++)
    //     cout<<L<<' '<<R<<endl;
    vector<int> ans;
    ans.push_back(a[1].second);
    // int ans=1;
    int mx=a[1].second;
    int mn=a[1].second;
    for(int i=2;i<=n;i++){
        if(R>ans.back()){
            ans.push_back(R);
        }
        else{
            int temp=ans.back();
            while(!ans.empty()&&R<=ans.back())
                ans.pop_back();
            ans.push_back(temp);
        }
        // if(R>mn){
        //     if(R>mx){
        //         mx=R;
        //         ans.push_back(R);
        //     }
        // }
        // else{
        //     mn=R;
        //     ans.clear();
        //     ans.push_back(R);
        // }
        // cout<<i<<' '<<ans.size()<<' '<<mn<<' '<<mx<<endl;
    }
    cout<<ans.size()<<endl;
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