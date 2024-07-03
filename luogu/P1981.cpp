#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair
const int MOD=10000;
stack<int> x;
void solve()
{
    int a,b;
	char c;
	cin>>a;
	a=a%MOD;
	x.push(a);
	while(cin>>c>>b)
	{
		if(c=='*')
		{
			a=x.top();
			x.pop();
			x.push(a*b%MOD);
		}
		else
			x.push(b);
	}
	int ans=0;
	while(x.size())
	{
		ans+=x.top();
		ans%=MOD;
		x.pop();
	}
	cout<<ans%MOD;
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