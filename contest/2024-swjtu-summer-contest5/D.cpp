#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int a[N],b[N],c[N];

void solve()
{
    int x,y,A,B,C;
    cin>>x>>y>>A>>B>>C;
    for(int i=1;i<=A;i++)
        cin>>a[i];
    for(int j=1;j<=B;j++)
        cin>>b[j];
    for(int k=1;k<=C;k++)
        cin>>c[k];
    int na=A,nb=B,nc=C;
    sort(a+1,a+1+A);
    sort(b+1,b+1+B);
    sort(c+1,c+1+C);
    int ans=0;
    int sum=x+y;
    while(x||y){
        if(y==0){
            if(a[na]>=c[nc]){
                ans+=a[na];
                na--;
                x--;
                sum--;
            }
            else{
                ans+=c[nc];
                nc--;
                sum--;
            }
        }
        else if(x==0){
            if(b[nb]>=c[nc]){
                ans+=b[nb];
                nb--;
                y--;
                sum--;
            }
            else{
                ans+=c[nc];
                nc--;
                sum--;
            }
        }
        else if(a[na]>=b[nb]&&a[na]>=c[nc]&&x){
            ans+=a[na];
            na--;
            x--;
            sum--;
        }
        else if(b[nb]>=a[na]&&b[nb]>=c[nc]&&y){
            ans+=b[nb];
            nb--;
            y--;
            sum--;
        }
        else if(c[nc]>=a[na]&&c[nc]>=b[nb]){
            ans+=c[nc];
            nc--;
            sum--;
        }
        if(sum==0)
            break;
    }
    cout<<ans<<endl;
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