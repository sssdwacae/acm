#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define int long long
#define mp make_pair

const int MAXN = 60000;
int prime[MAXN + 1];
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int ans[20005];
void solve()
{
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
    return;
}


void init()
{
    // cout<<prime[1]<<' '<<prime[2]<<endl;
    for(int i=1;i<=prime[0];i++)
        for(int j=i+1;j<=prime[0];j++){
            int num=prime[i]*prime[j];
            int a=1,b=num,c=prime[i],d=prime[j];
            //a c d b
            int mx=min(min(c-a,d-c),b-d);
            // if(num==6)
            //     cout<<"?"<<mx<<endl;
            if(mx>1e4){
                if(ans[10000]==0)
                    ans[10000]=num;
                else
                    ans[10000]=min(num,ans[10000]);
            }
            else{                
                if(ans[mx]==0)
                    ans[mx]=num;
                else
                    ans[mx]=min(ans[mx],num);
            }
            // if(num==6)
            //     cout<<ans[1]<<endl;
        }
    for(int i=10000;i>=1;i--){
        if(ans[i-1])
            ans[i-1]=min(ans[i],ans[i-1]);
        else
            ans[i-1]=ans[i];
    }
    // cout<<ans[1]<<endl;
    // cout<<ans[10000]<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getPrime();
    int T;
    cin >> T;
    // cout<<prime[0]<<' '<<endl;
    init();
    // cout<<ans[10000];
    while (T--)
        solve();
    return 0;
}