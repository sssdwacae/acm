#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

double f(double x,int n)
{
    if(n==1){
        return x/(1+x);
    }
    else
        return x/(n+f(x,n-1));
}

void solve()
{
    int n;
    double x;
    cin>>x>>n;
    printf("%.2lf",f(x,n));
    // cout<<f(x,n);
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