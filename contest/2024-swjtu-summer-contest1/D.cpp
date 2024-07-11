#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

const int M=10;
int a[M][M],b[M][M];
// int check[M][M];
int ans1=1e9;


struct Node{
    int x,y,n;
    Node(){}
    Node(int _x,int _y,int _n){
        x=_x;
        y=_y;
        n=_n;
    }
};
vector<Node> temp1,temp2;
bool cmp(Node a,Node b)
{
    if(a.n!=b.n)
        return a.n<b.n;
    else if(a.x!=b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}
int h,w;
bool check()
{
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(a[i][j]!=b[i][j])
                return false;
    return true;
}

// void dfs(int cnt,int pos)
// {
//     if(cnt>=ans1)
//         return;
//     if(pos==temp1.size())
//         return;
//     if(check()){
//         if(cnt<ans1)
//             ans1=cnt;
//         return;
//     }
//     for(int i=0;i<temp2.size();i++)
//         if(temp1[pos].n==temp2[i].n){
//             swap(a[temp1[pos].x][temp1[pos].y],b[temp2[i].x][temp2[i].y]);
//         }
// }
vector<Node> A,B;
void dfs2(int cnt,int pos)
{
    if(cnt>=ans1)
        return;
    if(pos==A.size())
        return;
    if(check()){
        if(cnt<ans1)
            ans1=cnt;
    }
    
}

void solve()
{
    
    cin>>h>>w;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin>>a[i][j];
    
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++){
            cin>>b[i][j];
            if(b[i][j]!=a[i][j]&&i==1){
                A.push_back(Node(i,j,a[i][j]));
                B.push_back(Node(i,j,b[i][j]));
            }
        }
    dfs2(0,0);
    sort(A.begin(),A.end(),cmp);
    sort(B.begin(),B.end(),cmp);
    // dfs();
    bool flag=true;
    
    for(int i=0;i<A.size();i++){
        if(A[i].n!=B[i].n){
            cout<<-1;
            return;
        }
        else if(B[i].x==1&&A[i].x==1&&A[i].y!=B[i].y){
            temp1.push_back(A[i]);
            temp2.push_back(B[i]);
            flag=false;
        }
    }
    if(flag){
        cout<<0;
        return;
    }
    else{
        cout<<temp1.size()<<endl;
        // dfs(0,0);
        // for(int i)
        cout<<ans1;
    }
    return;
}

/*
不同行列，三次
 1 2
 3

 2 1
 3

 3 1
 2

 1 3
 2
*/

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