#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

bool cmp1(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}

void solve()
{
    int n,m;
    double k;
    cin>>n>>m>>k;
    double r;
    cin>>r;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(mp(i,temp));
    }
    sort(v.begin(),v.end(),cmp1);
    while(v[n-1-m]>)
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