#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int l,r;
const int MOD=1e9+7;
void solve()
{
    cin>>l>>r;
    if(r-l>=10)
        cout<<0<<endl;
    else{
        int temp=1;
        for(int i=l;i<=r;i++){
            int n=i;
            while(n){
                temp*=n%10;
                temp%=MOD;
                n/=10;
            }
        }
        cout<<temp<<endl;
    }
    
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