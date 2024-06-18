#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define pii pair<int,int>
#define mk make_pair
#define int long long

struct cmp{
    bool operator()(pii &a,pii &b){
        return a.second>b.second;
    }
};

signed main()
{
    int n;
    cin>>n;
    priority_queue<pii,vector<pii>,cmp> q1,q2;
    for(int i=1,x,y,a,b;i<=n;i++){
        cin>>x>>y>>a>>b;
        if(a==1&&b==1){
            if(x<y)
                q1.push(mk(i,x));
            else
                q2.push(mk(i,y));
        }
        else if(a==0)
            q2.push(mk(i,y));
        else
            q1.push(mk(i,x));
    }   
    cout<<q1.size()<<' ';
    while(!q1.empty()){
        int temp=q1.top().first;
        cout<<temp<<' ';
        q1.pop();
    }
    cout<<'\n';
    cout<<q2.size()<<' ';
    while(!q2.empty()){
        int temp=q2.top().first;
        cout<<temp<<' ';
        q2.pop();
    }
    return 0;
}