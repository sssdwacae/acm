#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    if(a[0]!=1||a[1]!=1||n<10||n>13){
        cout<<"No\n";
        return;
    }
    for(int i=2;i<n-1;i++)
        if(a[i]-a[i-1]>2){
            cout<<"No\n";
            return;
        }
    cout<<"Yes\n";
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