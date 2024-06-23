#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n,m;
string s1,s2;
int a[N];

void solve()
{
    cin>>m>>n;
    cin>>s1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>s2;
    sort(a+1,a+1+n);
    sort(s2.begin(),s2.end());
    int pos=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]&&i!=n){
            s2.erase(s2.begin()+s2.size()-1);
        }
        else{
            s1[a[i]-1]=s2[pos++];
        }
    }
    cout<<s1<<endl;
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