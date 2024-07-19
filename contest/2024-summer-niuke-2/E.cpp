#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+5;
#define int long long
#define mp make_pai
void solve()
{
    int x;
    cin>>x;
    int num=x-((long long)1<<__builtin_ctzll(x));
    if(num)
        cout<<num<<endl;
    else
        cout<<-1<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // cout<<(long long )pow(2,58)<<endl;
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}