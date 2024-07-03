#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

string fun()
{
    char c;
    int n;
    string s,temp;
    while(cin>>c){
        if(c=='['){
            cin>>n;
            s=fun();
            while(n--)
                temp+=s;
        } 
        else{
            if(c==']')
                return temp;
            else
                temp+=c;
        }  
    }
    return temp;
}

void solve()
{
    cout<<fun();
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