#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n,k;
string s;
vector<int> x;
bool check(int mid)
{
    int start=x[0];int cnt=1;
    for(int i=1;i<(int)x.size();i++){
        if(start+mid-1<x[i]){
            start=x[i];
            cnt++;
        }
        else{
            continue;
        }
        if(cnt>k)   
            return false;
    }
    if(cnt<=k)
        return true;
    else
        return false;

}
void solve()
{
    cin>>n>>k;
    cin>>s;
    x.clear();
    for(int i=0;i<n;i++)
        if(s[i]=='1')
            x.push_back(i);
    // for(int i=0;i<x.size();i++)
    //     cout<<x[i]<<' ';cout<<endl;
    //1 开灯
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
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