#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int a,b;
    cout<<"? 1 2"<<endl;
    flush(stdout);
    cin>>a;
    cout<<"? 2 1"<<endl;
    flush(stdout);
    cin>>b;
    cout<<'!'<<a+b<<endl;
    flush(stdout);
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