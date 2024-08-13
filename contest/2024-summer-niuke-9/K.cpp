#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if(k==1){
        cout<<ans;
        return;
    }
    int mx=ans;
    int temp;
    for(temp=1;temp<=mx;temp++){
        int cnt=temp;
        for(int i=1;i<=n;i++){
            int tt=a[i];
            while(tt>temp){
                tt/=k;
                cnt++;
            }
        }
        cout<<temp<<":"<<cnt<<endl;
        // if(ans!=mx&&ans<cnt)
        //     break;
        ans=min(ans,cnt);
    }
    int kk=temp;
    for( temp=kk/k;temp<=kk;temp++){
        int cnt=temp;
        for(int i=1;i<=n;i++){
            int tt=a[i];
            while(tt>temp){
                tt/=k;
                cnt++;
            }
        }
        cout<<temp<<":"<<cnt<<endl;
        if(ans!=mx&&ans<cnt)
            break;
        ans=min(ans,cnt);
    }
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