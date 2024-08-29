#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

#define L a[i].first
#define R a[i].second
int n;
bool check(int x,vector<pair<int,int>> a)
{
    multiset<int> s1,s2;
    for(int i=1;i<=n;i++){
        if(R==0){//颜色 0
            if(s2.empty()){
                s1.insert(L);
                continue;
            }
            if(s2.lower_bound(x-L)==s2.end())//没找到
                return false;
            else
                s2.erase(s2.lower_bound(x-L));
        }
        else{
            if(s1.empty()){
                s2.insert(L);
                continue;
            }
            if(s1.lower_bound(x-L)==s1.end())//没找到
                return false;
            else
                s1.erase(s1.lower_bound(x-L));
        }
    }
    return true;
}

void solve()
{
    cin>>n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>L;
    for(int i=1;i<=n;i++)
        cin>>R;
    int left=0,right=2e8+1;
    int mid=(left+right+1)/2;
    while(left<right){
        mid=(left+right+1)/2;
        if(check(mid,a))
            left=mid;
        else
            right=mid-1;
    }
    cout<<left<<endl;
    // int temp=1;
    // for(int i=1;;i++){
    //     temp*=2;
    //     if(temp>2e8+1){
    //         cout<<i<<endl;
    //         break;
    //     }
    // }
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