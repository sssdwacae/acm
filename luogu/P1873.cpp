#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e7+5;
#define int long long
#define mp make_pair

int n,m;
int h[N];

void solve()
{
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        maxn=max(maxn,h[i]);
    }
    int l=0,r=maxn;
    // cout<<l<<r;
    while(l<=r){
        int mid=(l+r)/2;
        int sum=0;
        for(int i=1;i<=n;i++)
            if(h[i]>mid)
                sum+=h[i]-mid;
        if(sum<m)
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<r;
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