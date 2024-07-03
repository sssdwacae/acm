#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e6+5;
#define ll long long
#define mp make_pair

int a[N];
int n,q;
int fun(int x)
{
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]>=x)
            r=mid;
        else   
            l=mid+1;
    }
    if(a[l]!=x)
        return -1;
    return l;
}

void solve()
{
    
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=q;i++){
        int temp;
        cin>>temp;
        cout<<fun(temp)<<' ';
    }
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