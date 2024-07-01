#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int akm(int m,int n)
{
    if(m==0){
        return n+1;
    }
    else if(n==0&&m>0){
        return akm(m-1,1);
    }
    else{
        return akm(m-1,akm(m,n-1));
    }
}

void solve()
{
    int m,n;
    cin>>m>>n;
    cout<<akm(m,n);
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