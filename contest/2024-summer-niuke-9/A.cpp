#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n,m;
    cin>>n>>m;
    // cout<<n<<m<<endl;
    // getchar();
    int x,y;
    string s[501];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='x'){
                int temp=j;
                while(s[i][temp]=='x')
                    temp++;
                int temp2=i;
                while(s[temp2][j]=='x')
                    temp2++;
                temp2=temp2-i;
                temp=temp-j;
                for(int i=2;i<=min(temp,temp2);i++){
                    while(temp%i==0&&temp2%i==0){
                        temp/=i;
                        temp2/=i;
                    }
                }
                for(int k=1;k<=temp2;k++){
                    for(int q=1;q<=temp;q++)
                        cout<<"x";
                    cout<<endl;
                }
                return;
            }
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    T=1;
    // cin>>T;
    while(T--)
        solve();     
    return 0;
}