#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++)
        cin>>w[i];
    vector<int> dp(n,0);
    dp[0]=w[0],dp[1]=w[0];
    for(int i=2;i<n;i++){
        if(dp[i]){
            if(dp[i-2]+w[i-1]<dp[i-1]+w[i]&&dp[i-2]+w[i-1]<dp[i]){
                dp[i]=dp[i-2]+w[i-1];
            }
            else if(dp[i-1]+w[i]<dp[i]){
                dp[i]=dp[i-1]+w[i];
                if(i<n-1)
                dp[i+1]=dp[i];
            }
        }
        else if(dp[i-2]+w[i-1]<dp[i-1]+w[i]){
            dp[i]=dp[i-2]+w[i-1];
        }
        else{
            dp[i]=dp[i-1]+w[i];
            if(i<n-1)
                dp[i+1]=dp[i];
        }
    }
    int ans=dp[n-1];
    // memset(dp,0,sizeof(dp));
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<' ';cout<<endl;
    vector<int> db(n,0);
    int t=w[0];
    w.erase(w.begin());
    w.push_back(t);
    db[0]=w[0];
    db[1]=w[0];
    for(int i=2;i<n;i++){
        if(db[i]){
            if(db[i-2]+w[i-1]<db[i-1]+w[i]&&db[i-2]+w[i-1]<db[i]){
                db[i]=db[i-2]+w[i-1];
            }
            else if(db[i-1]+w[i]<db[i]){
                db[i]=db[i-1]+w[i];
                if(i<n-1)
                db[i+1]=db[i];
            }
        }
        else if(db[i-2]+w[i-1]<db[i-1]+w[i]){
            db[i]=db[i-2]+w[i-1];
        }
        else{
            db[i]=db[i-1]+w[i];
            if(i<n-1)
                db[i+1]=db[i];
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<db[i]<<' ';cout<<endl;
    ans=min(ans,db[n-1]);
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