#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e7+5;
#define int long long
#define mp make_pair

int a[N],b[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int sum1=0,sum2=0,sum3=0;
    for(int j=1;j<=n;j++){
        cin>>b[j];
        sum1+=a[j]*3;
        sum2+=b[j]*2;
        sum3+=a[j]-b[j];
    }
    double ans=1.0*(sum1-sum2)/sum3;
    printf("%.6lf",ans);
    return;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}