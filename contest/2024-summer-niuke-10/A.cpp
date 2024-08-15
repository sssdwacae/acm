#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    string s;
    cin>>s;
    int cnt1=0,cnt2=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='Y')
            cnt1++;
        else if(s[i]=='N')
            cnt2++;
    }
    if(cnt1>=4)
        cout<<1;
    else if(cnt2>=2)
        cout<<-1;
    else
        cout<<0;
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