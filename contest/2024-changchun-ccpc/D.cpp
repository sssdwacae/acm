#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

#define X a[i].first
#define Y a[i].second

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>X>>Y;
    int x0=a[1].first;
    int y0=a[1].second;
    for(int j=2;j<=n;j++){//和第j个点构成平行线
        int x1=a[j].first;
        int y1=a[j].second;
        map<int,vector<int>> check;
        bool flag=true;
        for(int i=1;i<=n;i++){
            check[Y*(x1-x0)-(y1-y0)*X].push_back(i);
            if(check[Y*(x1-x0)-(y1-y0)*X].size()==1)
                flag=false;
            else
                flag=true;
            // if(check.size()>k){
            //     flag=false;
            //     break;
            // }
        }
        if(flag==false)
            continue;
        if(check.size()==k){
            vector<pair<int,vector<int>>> ans(check.begin(),check.end());
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].second.size()<<' ';
                for(int k=0;k<ans[i].second.size();k++)
                    cout<<ans[i].second[k]<<' ';
                cout<<endl;
            }
            return;
        }
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