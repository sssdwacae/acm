#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

int n;
ll l,r;


void solve()
{
    queue<ll> q;
    cin>>n>>l>>r;
    int ans=0;
    ll sum=0;
    for(int i=1,temp;i<=n;i++){
        cin>>temp;
        q.push(temp);
        sum+=temp;
        if(sum>=l&&sum<=r){
            ans++;
            while(sum){
                sum-=q.front();
                q.pop();
            }
        }
        else if(sum>r){
            while(sum>r){
                sum-=q.front();
                q.pop();
            }
            if(sum>=l&&sum<=r){
                ans++;
                while(sum){
                    sum-=q.front();
                    q.pop();
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
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}
