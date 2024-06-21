#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n;
int a[N],check[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int temp=fabs(a[i]-a[i+1]);
        if(check[temp]||temp<1||temp>n-1){
            cout<<"Not jolly\n";
            return ;
        }
        else{
            check[temp]=1;
        }
    }
    cout<<"Jolly\n";
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