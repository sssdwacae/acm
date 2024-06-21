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
    queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(i);
    bool flag=true;//2 ture  3 false
    while(q.size()>3){
        int l=q.size();
        if(flag){//2
            for(int i=1;i<=l/2;i++){
                int temp=q.front();
                q.pop();q.pop();
                q.push(temp);
            }
            if(l&1){
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
        }
        else{//3
            for(int i=1;i<=l/3;i++){
                int temp=q.front();
                q.pop();
                q.push(temp);

                temp=q.front();
                q.pop();
                q.push(temp);

                q.pop();
            }
            while(l%3){
                l--;
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
        }
        flag=!flag;
    }
    while(!q.empty()){
        int temp=q.front();
        cout<<temp<<' ';
        q.pop();
    }
    cout<<endl;
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