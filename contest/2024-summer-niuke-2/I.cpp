#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=3e3+5;
#define int long long
#define mp make_pair

int dp[N][N];
int a[N*2];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        if(a[i]==a[i-1])
            dp[i-1][i]=2*a[i];
    }
    for(int len=2;len<2*n;len++)//长度从3开始
        for(int l=1;l+len<=2*n;l++){
            int r=l+len;
            if(a[l]==a[r]){
                dp[l][r]=max(dp[l][r],a[l]*(len+1));
                for(int p=l+1;p<=r-1;p++)
                    for(int q=p+1;q<=r-1;q++)
                        dp[l][r]=max(dp[l][r],dp[p][q]+(len+1-(q-p+1))*a[l]);
            }
            for(int k=l;k<r;k++)
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
        }
    cout<<dp[1][2*n];
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