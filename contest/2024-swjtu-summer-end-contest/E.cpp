#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int x,y;
    cin>>x>>y;
    string s;
    cin>>s;
    int nxj=0,nyj=0,nxf=0,nyf=0;
    for(int i=0;i<s.size();i++){
        switch(s[i]){
            case 'R':
                nxj++;
                break;
            case 'L':
                nxf++;
                break;
            case 'U':
                nyj++;
                break;
            case 'D':
                nyf++;
                break;
        }
    }
    if(-nyf<=y&&y<=nyj&&-nxf<=x&&x<=nxj){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}