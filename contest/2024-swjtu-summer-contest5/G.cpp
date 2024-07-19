#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int cnt=0;

void solve()
{
    int w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    int ans=1e9;
    if(w1<w2)
        ans=min(ans,(w2-w1)*h1);
    if(w2<w1)
        ans=min(ans,(w1-w2)*h2);
    if(h1<h2)
        ans=min(ans,(h2-h1)*w1);
    if(h2<h1)
        ans=min(ans,(h1-h2)*w2);
    if(ans==100000||h1==h2||w1==w2)
        ans=0;
    swap(w1,h1);
    if(w1<w2)
        ans=min(ans,(w2-w1)*h1);
    if(w2<w1)
        ans=min(ans,(w1-w2)*h2);
    if(h1<h2)
        ans=min(ans,(h2-h1)*w1);
    if(h2<h1)
        ans=min(ans,(h1-h2)*w2);
    if(ans==100000||h1==h2||w1==w2)
        ans=0;
    double t=w1*h1+w2*h2+1.0*ans/2;
    cout<<"Case "<<++cnt<<": ";
    cout<<t<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    // T=1;
    while(T--)
        solve();     
    return 0;
}