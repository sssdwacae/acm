#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=6e2+5;
#define ll long long
#define mp make_pair

int a[N][N];
int b[N][N];
int c[N][N];

int n,m,k;

void solve()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int sum0=0,sum1=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            b[i][j+1]=s[j]-'0';
            if(b[i][j+1])
                sum1+=a[i][j+1];
            else 
                sum0+=a[i][j+1];
        }
    }
    if(sum0==sum1){
        cout<<"YES\n";
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
    int temp=k*k;
    for(int i=1;i+k-1<=n;i++)
        for(int j=1;j+k-1<=m;j++){
            int sum=c[i+k-1][j+k-1]-c[i-1][j+k-1]-c[j+k-1][j-1]+c[i-1][j-1];
            int n0=temp-sum;
            int n1=sum;
            int y=fabs(sum1-sum0);
            int x=fabs(n1-n0);
            if(x==0)
                continue;
            if(y%x==0){
                cout<<"YES\n";
                return;
            }
        }
    cout<<"NO\n";
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