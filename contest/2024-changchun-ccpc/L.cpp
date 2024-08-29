#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int k,x,y;
    cin>>k>>x>>y;
    if(k%2){
        if(k==1){
            cout<<x+y<<endl;
            return;
        }
        int cnt=0;
        if((k-1)/2*x==y){
            cout<<y<<endl;
        }
        else if(y/((k-1)/2)<x){  // x多
            int mid=(k-1)/2;
            int temp=y/mid;
            cnt+=temp;
            y-=temp*mid;
            x-=temp;
            if(x!=0&&y*2+x>=k){
                cnt++;
                x-=(k-y*2);
            }
            cnt+=x/k;
            cnt+=y*2/(k+1);
            cout<<cnt<<endl;
        }
        else{ //y多
            int mid=(k-1)/2;
            int temp=y/mid;
            cnt+=x;
            y-=x*mid;
            x=0;
            cnt+=y*2/(k+1);
            cout<<cnt<<endl;
        }
    }
    else{
        cout<<(x+y*2)/k<<endl;
    }
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