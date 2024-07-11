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
    //状态转换
    int m1,m2,ans=0;
    cin>>m1;//第一个点对于先手来说是必败态
    //距离最近的必败态
    m2=0x3f3f3f3f;
    // cout<<minn<<' '<<mx<<endl;
    for(int i=2,temp;i<=n;i++){
        cin>>temp;
        if(temp>m1){//此点不是必败态
            //判断是否是比当前最大的小，是则为必胜态度
            if(temp<m2){
                ans++;
                // cout<<temp<<' ';
                m2=temp;//m2是必胜态
            }
        }
        else
            m1=temp;
    }
    cout<<ans<<endl;
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