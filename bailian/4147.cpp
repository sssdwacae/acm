#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

void  h(int n,char ch1,char ch2,char ch3)
{
	if(n==1){
	    cout<<n<<':'<<ch1<<"->"<<ch3<<endl;
        return;
    }
    h(n-1,ch1,ch3,ch2);
    cout<<n<<':'<<ch1<<"->"<<ch3<<endl;
    h(n-1,ch2,ch1,ch3);
    return;
}


/*
    123
    23   0   1
    3    2    1
    3    12   0

    0    12   3
    1    2    3

    1    0    23
    0    0    123
*/
void solve()
{
    int n;
	cin>>n;
    char a,b,c;
    cin>>a>>b>>c;
	h(n,a,b,c);
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