#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int a[N];
int b[15];
int cnt=0;
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int ans=0;
    int temp=0;
    for(int i=1;i<=m;i++){
        temp+=b[i];
        // cout<<temp<<endl;
        ans+=a[temp];
        ans+=20*(b[i]-1);
    }
    cout<<"Case "<<++cnt<<": ";
    cout<<ans<<endl;
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