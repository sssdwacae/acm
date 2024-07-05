#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

void solve()
{
    ll n;
    cin>>n;
    if(!n){
        cout<<"00";
        return;
    }
    string s;
    int a[10];
    a[8]=1;
    while(n){
        int cnt=0;
        while(cnt<7){
            a[++cnt]=n%2;
            n/=2;
        }
        int temp1=0,temp2=0,k=1;
        for(int i=1;i<=4;i++){
            temp1+=k*a[i];
            k*=2;
        }
        k=1;
        for(int i=5;i<=8;i++){
            temp2+=k*a[i];
            k*=2;
        }
        char c1,c2;
        if(temp1>=0&&temp1<=9)
            c1=temp1+'0';
        else
            c1=temp1-10+'A';
        if(temp2>=0&&temp2<=9)
            c2=temp2+'0';
        else
            c2=temp2-10+'A';
        s=s+c2;
        s=s+c1;
    }
    int temp=0;
    int l=s.size()-2;
    if(s[l]>='0'&&s[l]<='9')
        temp=s[l]-'0';
    else
        temp=s[l]-'A'+10;
    temp-=8;
    if(temp>=0&&temp<=9)
        s[l]=temp+'0';
    else
        s[l]=temp-10+'A';
    for(int i=0;i<s.size();i+=2)
        cout<<s[i]<<s[i+1]<<' ';
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