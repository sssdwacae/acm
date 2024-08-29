#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

void solve()
{
    int mx=0;
    int cnt=0;
    int n,temp;
    cin>>n;
    while(n--){
        cin>>temp;
        if(temp>mx){
            mx=temp;
            cnt=1;
        }
        else if(temp==mx){
            cnt++;
        }
    }
    if(cnt&1)
        cout<<"Alice";
    else
        cout<<"Bob";
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