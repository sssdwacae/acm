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
    vector<int> l(n+1),r(n+1);
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        mx=max(l[i],mx);
        mx=max(r[i],mx);
    }
    int nn=-1;
    while(mx){
        mx/=2;
        nn++;
    }
    int ans=0;
    for(int i=nn;i>=0;i--){//判断位数
        bool flag=true;//假设目前位数能取到1
        for(int j=1;j<=n;j++){
            if(0==((r[j]>>i)&1)){//取不到1
                flag=false;
                break;
            }
        }
        /*
            r     xxxx 1  xxxxx
            l     xxxx 1  xxxxx
                  xxxx 0  xxxxx
        */
        if(flag){
            ans+=(1<<i);
        }
        else{
            for(int j=1;j<=n;j++){
                if(1==((r[j]>>i)&1)){
                    r[j]=(1<<i)-1;
                    if((l[j]>>i)&1){
                        l[j]=l[j]%(1<<i);
                    }
                    else{
                        l[j]=(1<<i)-1;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("in.txt","r",stdin);
    freopen("solout.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}