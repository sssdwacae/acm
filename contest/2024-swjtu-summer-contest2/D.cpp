#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int x,y,z;
/*
    (x+y)%k=z;
    cin>>x>>y>>z;

*/

void solve()
{
    cin>>x>>y>>z;

    int ans=x+y-z;
    if(ans==0){
        cout<<2000000000<<endl;
        return;
    }
    if((x+y)%ans == z && ans > z && ans >= 1 && ans <= 2000000000 && x<ans){
            cout<<ans<<endl;
    }
    else
        cout<<-1<<endl;
    return;
}

signed main()
{
    // cout<<107%6<<endl;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}