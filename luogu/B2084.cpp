#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

bool isprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

void solve()
{   
    int n;
    cin>>n;
    for(int i=sqrt(n)-1;i<n;i++)
        if(n%i==0){
            if(isprime(i)&&isprime(n/i)){
                cout<<max(i,n/i);
                return;
            }
        }

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