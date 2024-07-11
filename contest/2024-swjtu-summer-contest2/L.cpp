#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int n,m,T;

const int M=3005;
int check[M];
int dp[M][M];//dp i j  是前i个物品，j的体积

void solve()
{
    cin>>n>>m>>T;
    vector<vector<int> > graph(n+1);
    vector<int> w(n,0);
    for(int i=1;i<=n-1;i++)
        cin>>w[i];
    vector<int> v(n,0);
    check[1]=1;
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y;
        if(x==y)
            continue;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int pos=q.front();
        q.pop();
        for(int i=0;i<graph[pos].size();i++){
            if(check[graph[pos][i]]==0){
                q.push(graph[pos][i]);
                check[graph[pos][i]]=1;
                v[graph[pos][i]-1]=v[pos-1]+1;
            }
        }
    }
    for(int i=1;i<=n-1;i++)
        v[i]=2*v[i];
    // for(int i=1;i<=n-1;i++)
    //     cout<<v[i]<<' ';cout<<endl;
    // for(int i=1;i<=n-1;i++)
    //     cout<<w[i]<<' ';cout<<endl;
    // vector<int> ans(T);
    
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<=T;j++)
            for(int k=0;k<=j/v[i];k++){
                if(j<k*v[i])
					dp[i][j]=max(dp[i-1][j],dp[i][j]);
				else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*v[i]]+k*w[i]);
        }
    for(int j=1;j<=T;j++){
        dp[n-1][j]=max(dp[n-1][j],dp[n-1][j-1]);
        cout<<dp[n-1][j]<<' ';
    }
    // cout<<dp[n-1][T];
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