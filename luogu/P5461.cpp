#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n;

int ans[1500][1500];

void work(int x,int y,int n)
{
    if(n==1)
        return;
    for(int i=x;i<x+n/2;i++)
        for(int j=y;j<y+n/2;j++)
            ans[i][j]=1;
    // work(x,y,n/2);
    work(x,y+n/2,n/2);
    work(x+n/2,y,n/2);
    work(x+n/2,y+n/2,n/2);
    return;
}

void solve()
{
    cin>>n;
    n=pow(2,n);
    work(1,1,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<1-ans[i][j]<<' ';
        cout<<endl;
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