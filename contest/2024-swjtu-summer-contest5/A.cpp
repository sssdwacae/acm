#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    bool flag=true;
    int pos=0;
    int nx=0;
    for(int i=1,temp;i<=n;i++){
        cin>>temp;
        if(flag){
            if(nx==0){
                if(temp==0){
                    nx=1;
                }
                else{
                    flag=false;
                    pos=i;
                }
            }
            else{
                if(nx==temp){
                    nx++;
                }
                else if(nx<temp){
                    flag=false;
                    pos=i;
                }
            }
        }
    }
    if(flag)
        cout<<-1;
    else
        cout<<pos;
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