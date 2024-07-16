// C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll mod=ll(1e9)+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll q;
    ll pos=0;
    vector<ll> a(5e5+10), b(5e5+10), pre(5e5+10);
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        pos=pos-x+1;
        a[pos]=y;
        b[pos]=pos*y%mod;
        pre[pos]=(pre[pos-1]+b[pos])%mod;
        cout<<pre[pos]<<endl;
    }
    
}