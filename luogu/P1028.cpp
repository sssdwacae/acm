#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int ans;
int f[N];
void fun(int n)
{
    ans++;
    if(n==1)
        return;
    for(int i=1;i<=n/2;i++){
        //  cout<<i<<' '<<n<<endl;
        fun(i);
    }
    return;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            f[i]+=f[j]; 
        }
        f[i]++; 
    }
    cout<<f[n];
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