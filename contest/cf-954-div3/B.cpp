#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n,m;

void solve()
{
    cin>>n>>m;
    vector<int> temp(m+2,-0x3f3f3f);
    vector<vector<int> > a(n+2,temp);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    // cout<<'?';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            bool flag=true;
            if(i!=1&&a[i-1][j]>a[i][j])
                flag=false;
            if(i!=n&&a[i+1][j]>a[i][j])
                flag=false;
            if(j!=1&&a[i][j-1]>a[i][j])
                flag=false;
            if(j!=m&&a[i][j+1]>a[i][j])
                flag=false;
            if(flag)
                a[i][j]=max(max(a[i][j+1],a[i][j-1]),max(a[i-1][j],a[i+1][j]));
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
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