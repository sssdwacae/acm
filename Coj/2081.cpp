#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

ll HtoD(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'A'+10;
}

void solve()
{
    string s;
    cin>>s;
    while(s.size()%3)
        s='0'+s;
    bool flag=false;
    for(int i=0;i<s.size();i+=3){
        ll temp=HtoD(s[i])*256+HtoD(s[i+1])*16+HtoD(s[i+2]);
        ll a[10];
        for(int j=1;j<=4;j++){
            a[j]=temp%8;
            temp/=8;
        }
        for(int j=4;j>=1;j--){
            if(a[j])
                flag=true;
            if(flag)
                cout<<a[j];
        }
    }
    cout<<endl;
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