#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[0]){
            cout<<"Wrong Answer";
            return;
        }
    }
    cout<<"Correct";
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