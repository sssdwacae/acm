#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// #define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int a,b=0;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>a;
    b=a;
    while(b==a){
        cout<<"? 1 2"<<endl;
        fflush(stdout);
        cin>>b;
    }
    cout<<'!'<<a+b<<endl;
    fflush(stdout);
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