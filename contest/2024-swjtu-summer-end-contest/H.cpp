#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=5e3+5;
#define int long long
#define mp make_pair

// int a[N],b[N],dp[N][N];
// int check[N][N];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1,0),b(n+1,0);
    vector<vector<int> > dp(n+1,vector<int>(k+1,0));
    vector<vector<int> > check(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    //dp  1-n 选了j段
    // max  dp[i][j]  =  dp[i-m+1][j-1]
    //r=i  l=i-m+1
    for(int i=m;i<=n;i++){//从1到i，选j段
        int l=i-m+1,r=i;//i=2,j=2  r2l2
        for(int j=1;j<=k;j++){
            // if(i==2&&j==2)
            //     cout<<check[l][j-1]<<'?'<<endl;
            if(dp[l-1][j-1]+b[r]-b[l-1]>dp[i][j]&&check[l-1][j-1]<l){
                dp[i][j]=dp[l-1][j-1]+b[r]-b[l-1];
                check[i][j]=i;

            }
            if(dp[i-1][j]>dp[i][j]){
                dp[i][j]=dp[i-1][j];
                check[i][j]=check[i-1][j];
            }
            if(dp[i][j-1]>dp[i][j]){
                dp[i][j]=dp[i][j-1];
                check[i][j]=check[i][j-1];
            }
        }
        
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=k;j++)
    //         cout<<dp[i][j]<<' ';cout<<endl;
    // }
    cout<<dp[n][k];
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