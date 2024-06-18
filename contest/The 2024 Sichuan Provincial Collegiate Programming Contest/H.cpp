#include<iostream>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin>>n;
    if(n%3==0)
        cout<<1<<' '<<n/3<<endl;
    else
        cout<<0<<' '<<n/3+n%3<<endl;
    return;
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}