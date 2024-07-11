#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair
const int MAXN=112222222233;
int a[20]={1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,11111111111,111111111111,1111111111111};

vector<int> ans;
set<int> check;
void dfs(int pos,int num,int cnt)
{
    if(num&&num<=MAXN&&cnt==3&&check.find(num)==check.end()){
        ans.push_back(num);
        check.insert(num);
    }
    else if(num&&num>MAXN||cnt>3)
        return;
    for(int i=0;i<12;i++)
        dfs(i,num+a[i],cnt+1);
    return;
}

void solve()
{
    dfs(0,0,0);
    //  cout<<ans.size();
    // return;
    sort(ans.begin(),ans.end());
    int n;
    cin>>n;
    // for(int i=0;i<=6;i++)
        // cout<<ans[i]<<' ';cout<<endl;
    cout<<ans[n-1];
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