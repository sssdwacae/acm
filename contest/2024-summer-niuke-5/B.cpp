#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(n*m==2){
        cout<<"Yes\n";
        return;
    }
    if(n*m%2){
        cout<<"No\n";
        return;
    }
    if(a&&b){
        cout<<"Yes\n";
        return;
    }
    if(a==0&&b==1){
        if(n%2==0&&m%3==0||n%3==0&&m%2==0||n%2==0&&m%2==0||n%2==0&&m%3!=2||m%2==0&&n%3!=2||n==2||m==2
        ){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    if(a==1&&b==0){
        if(n==1||m==1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    if(a==0&&b==0){
        cout<<"No\n";
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