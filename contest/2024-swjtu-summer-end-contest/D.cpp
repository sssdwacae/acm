#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int x,y;
    cin>>x>>y;
    if(x>y){
        cout<<"NO"<<endl;
        return;
    }
    else if(x==y){
        cout<<"YES"<<endl;
        return;
    }
    int a[35]={0};
    int cnt1=0,cnt2=0;
    int k=0;
    while(x){
        if(x%2){
            a[++cnt1]=k++;
        }else{
            k++;
        }
        x/=2;
    }
    // for(int i=1;i<=cnt1;i++)
    //     cout<<a[i]<<' ';cout<<endl;
    // cout<<cnt1<<endl;
    int b[35]={0};
    k=0;
    while(y){
        if(y%2){
            b[++cnt2]=k++;
        }else{
            k++;
        }
        y/=2;
    }
    if(cnt2>cnt1){
        cout<<"NO"<<endl;
        return;
    }
    int j=1;
    for(int i=1;i<=cnt2;i++){
        if(a[j]<=b[i])
            j++;
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    // for(int i=1;i<=cnt2;i++)
    //     cout<<b[i]<<' ';cout<<endl;
    cout<<"YES"<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    // cout<<(1&(2-1))<<' '<<(2&(3-2))<<endl;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}