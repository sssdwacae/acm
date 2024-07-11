#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

const int M=2e6+5;

map<pair<int,int>,int> m;
vector<int> v[M];
vector<int> ans[M];
int s[M];

int n;
int dfs(int root)//搜索到的根节点是root 数量
{
    if(v[root].size()==0||root>n){
        s[root]=1;
        return 1;
    }
    int sum=1;
    for(int i=0;i<v[root].size();i++){//root 节点能到达的节点
        sum+=dfs(v[root][i]);
    }
    s[root]=sum;
    return sum;
}

void solve()
{

    cin>>n;
    bool flag=false;
    for(int i=1,temp;i<=n-1;i++){
        cin>>temp;
        // if(temp!=1)
        //     flag=true;
        v[temp].push_back(i+1);
    }
    // if(!flag){
    //     cout<<n-2;
    //     return;
    // }
    dfs(1);
    // for(int i=1;i<=n;i++)
        // cout<<s[i]<<' ';cout<<endl; 
    int ans=0;
    for(int i=1;i<=n;i++){
        // cout<<v[i].size()<<endl;
        vector<int> sss;
        for(int j=0;j<v[i].size();j++){//首个
            // int temp=0;
            // for(int k=v[i].size()/2;k<v[i].size();k++){//末尾
                // temp+=s[v[i][k]];
            // }
            // ans+=s[v[i][j]]*temp;
            sss.push_back(s[v[i][j]]);
        }
        sort(sss.begin(),sss.end());
        int temp1=0,temp2=0;
        for(int j=0;j<sss.size()/2;j++){
            temp1+=sss[j];
        }
        for(int k=sss.size()/2;k<sss.size();k++){
            temp2+=sss[k];
        }
        ans+=temp1*temp2;
    }
    cout<<ans<<endl;
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