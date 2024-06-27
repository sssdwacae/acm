#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define int long long
#define mp make_pair
int n;
string s;

int fun(char c)
{
    return c-'0';
}

void solve()
{
    cin>>n;
    cin>>s;
    if(n==2){
        int temp=fun(s[0])*10+fun(s[1]);
        cout<<temp<<endl;
        return;
    }
    if(n==3){
        int ans=0;
        int temp1,temp2;
        temp1=10*fun(s[0])+fun(s[1]);
        temp2=fun(s[2]);
        ans=min(temp1*temp2,temp1+temp2);
        temp1=fun(s[0]);
        temp2=fun(s[1])*10+fun(s[2]);
        ans=min(min(temp1*temp2,temp1+temp2),ans);
        cout<<ans<<endl;
        return;
    }
    bool flag=false;
    for(int i=0;i<n;i++)
        if(s[i]=='0')
            flag=true;
    if(flag){
        cout<<0<<endl;
        return;
    }
    string S=s;
    for(int i=0;i<(int)s.size();i++)
        if(s[i]=='1'){
            s.erase(s.begin()+i);
            i--;
        }
    if((int)s.size()==0){
        cout<<11<<endl;
        return;
    }
    else if((int)s.size()==1){
        int temp=10+fun(s[0]);
        cout<<temp<<endl;
        return;
    }
    // s=S;
    flag=false;
    int pos=-1;
    for(int i=0;i<S.size()-1;i++){
        if(S[i]=='1'&&S[i+1]!='1'){
            pos=i;
            flag=true;
            break;
        }
    }
    if(flag){
        int ans=10*fun(S[pos])+fun(S[pos+1]);
        S.erase(S.begin()+pos);
        S.erase(S.begin()+pos);
        for(int i=0;i<(int)S.size();i++)
            if(S[i]!='1')
                ans+=fun(S[i]);
        cout<<ans<<endl;
        return;
    }

    flag=false;
    pos=-1;
    for(int i=0;i<S.size()-1;i++){
        if(S[i]=='1'){
            pos=i;
            flag=true;
            break;
        }
    }
    if(flag){
        int ans=10*fun(S[pos])+fun(S[pos+1]);
        S.erase(S.begin()+pos);
        S.erase(S.begin()+pos);
        for(int i=0;i<(int)S.size();i++)
            if(S[i]!='1')
                ans+=fun(S[i]);
        cout<<ans<<endl;
        return;
    }
    pos=-1;
    int mn=0x3f3f3f3f;
    for(int i=0;i<(int)s.size()-1;i++){
        int temp=10*fun(s[i])+fun(s[i+1]);
        if(temp<mn){
            mn=temp;
            pos=i;
        }
    }
    if(pos!=-1){
        s.erase(s.begin()+pos);
        s.erase(s.begin()+pos);
    }
    int temp=0;
    for(int i=0;i<(int)s.size();i++)
        if(s[i]!='1')
            temp+=fun(s[i]);
    cout<<mn+temp<<endl;
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