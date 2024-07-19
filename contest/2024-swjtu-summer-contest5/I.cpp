#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    string s;
    cin>>s;
    int n;
    cin>>n;

    if(n==1){
        int ans=0;
        ans=s[0]-'0';
        ans+=(s.size()-1)*9;
        cout<<ans<<endl;
    }
    else if(n==2){
        int ans=0;
        for(int i=2;i<s.size();i++){//总共的位数，未考虑最高位能算情况
            ans+=9*9*(i-1);
            // cout<<i<<" :"<<ans<<endl;
        }
        //  cout<<ans<<endl;
        ans+=9*(s[0]-'0'-1)*(s.size()-1);
        // cout<<ans<<endl;
        bool flag=false;//没找到第一位
        for(int i=1;i<s.size();i++){
            if(s[i]!='0'&&flag==false){
                ans+=s[i]-'0';
                flag=true;
            }
            else if(flag==true)
                ans+=9;
        }
        cout<<ans<<endl;
    }
    else if(n==3){
            // cout<<n<<endl;
        int ans=0;
        for(int i=3;i<s.size();i++){
            ans+=9*9*9*(i-1)*(i-2)/2;
        }
        // cout<<ans<<endl;//2916
        ans+=9*9*(s[0]-'0'-1)*(s.size()-1)*(s.size()-2)/2;//3888
        // cout<<ans<<endl;//6804
        bool flag1=false,flag2=false;
        int temp1=0,temp2=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!='0'){
                if(flag1==false){
                    temp1=s[i]-'0';
                    // cout<<temp1<<endl;
                    ans+=9*(temp1-1)*(s.size()-i-1);
                    ans+=9*9*(s.size()-i-1)*(s.size()-i-2)/2;
                    flag1=true;
                }
                else if(flag2==false){
                    temp2=s[i]-'0';
                    ans+=temp2;
                    ans+=9*(s.size()-i-1);
                    flag2=true;
                }
            }
        }
        cout<<ans<<endl;
    }
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