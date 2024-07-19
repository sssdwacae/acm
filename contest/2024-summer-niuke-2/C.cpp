#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    s1=' '+s1;
    s2=' '+s2;
    int now=-1;//0 全，1上，2下 -1,没有状态
    int cnt=0;//计数
    int temp=0,ans=0;
    int pre=0;
    for(int i=1;i<=n;i++){
        // string s="";
        // s=s+s1[i]+s2[i];
        // cout<<i<<":"s<<endl;
        if(s1[i]=='W'&&s2[i]=='R'){
            switch(now){
                case -1 :
                    now=2;temp++;break;
                case 1 :
                    ans=max(temp,ans);
                    temp=1;now=2;cnt=0;break;
                case 2:
                    temp++;break;
                case 0:
                    if(pre==-1){
                        temp++;cnt=0;pre=0;now=2;
                    }
                    if(pre==2){
                        if(cnt%2==0)
                            temp++;
                        cnt=0;pre=0;now=2;
                    }
                    else if(pre==1){
                        if(cnt&1)
                            temp++;
                        cnt=0;pre=0;now=2;
                    }
            }
        }
        else if(s1[i]=='R'&&s2[i]=='W'){
            switch(now){
                case -1 :
                    now=1;temp++;break;
                case 2 :
                    ans=max(temp,ans);
                    temp=1;now=1;cnt=0;break;
                case 1:
                    temp++;break;
                case 0:
                    if(pre==-1){
                        temp++;cnt=0;pre=0;now=1;
                    }
                    if(pre==2){
                        if(cnt%2&1)
                            temp++;
                        cnt=0;pre=0;now=1;
                    }
                    else if(pre==1){
                        if(cnt%2==0)
                            temp++;
                        cnt=0;pre=0;now=1;
                    }
            }
        }
        else if(s1[i]=='R'&&s2[i]=='R'){
            if(now!=0)
                pre=now;
            now=0;
            cnt++;
            temp+=2;
        }
        else if(s1[i]=='W'&&s2[i]=='W'){
            now=-1;
            cnt=0;
            ans=max(ans,temp);
            temp=0;
            // cout<<temp<<endl;
        }
    }
    ans=max(ans,temp);
    if(ans!=0)
        ans--;
    cout<<ans<<endl;
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