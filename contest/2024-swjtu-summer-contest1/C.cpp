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
    int cnt=1;
    while(b==a&&cnt<=25){
        cout<<"? 1 2"<<endl;
        fflush(stdout);
        cin>>b;
        cnt++;
    }
    if(a!=b){
        cout<<'!'<<a+b<<endl;
        fflush(stdout);
    }
    else{
        cout<<"? 1 3"<<endl;
        fflush(stdout);
        cin>>a;
        b=a;
        cnt=1;
        while(b==a&&cnt<=25){
            cout<<"? 1 3"<<endl;
            fflush(stdout);
            cin>>b;
            cnt++;
        }
        cout<<a+b<<endl;
        fflush(stdout);
    }
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