#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int a[N*4],b[N*4];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans=0;
    for(int j=1,i=1;i<=n;i++){
        if(a[i]>b[j]){
            j++;
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    T=1;
    //cin>>T;
    while(T--)
        solve();     
    return 0;
}