#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int m,k,h;

int check(int t)
{
    int nn=t;//4
    int ans=0;
    while(nn>=m){
        int temp=nn/m;
        ans+=temp*m;
        nn-=temp*m;
        nn+=temp*k;
    }
    return ans+nn;
}

void solve()
{
    
    cin>>m>>k>>h;
    if(h<=m){
        cout<<h<<endl;
        return;
    }
    else if(m<=k){
        cout<<m<<endl;
        return;
    }
    // cout<<check(4)<<endl;
    int l=1,r=h;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)>=h)
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    return;
}

signed main()
{
    freopen("in.txt","r",stdin);
    freopen("ansout.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}

