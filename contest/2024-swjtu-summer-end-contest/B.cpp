#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

// const int N=1e5+5;
#define ll long long
#define mp make_pair

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;y=_y;
    } 
};

// const int N=4e3+5;
// #define L 2000
map<pair<int,int>,int > checkxy,checkyx;
// int checkxy[N][N];
// int checkyx[N][N];

void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int> > x,y;
    map<int,int> yx,xy;
    for(int i=1,xx,yy;i<=n;i++){
        cin>>xx>>yy;
        x[xx].push_back(yy);
        y[yy].push_back(xx);
        checkyx[mp(yy,xx)]=1;//[yy+L][xx+L]++;
        checkxy[mp(xx,yy)]=1;//[xx+L][yy+L]++;
    }
    for(int i=1,xx,yy;i<=m;i++){
        cin>>xx>>yy;
        int num=0;
        num+=x[xx].size()*y[yy].size();//大本营为中心
        // cout<<num<<endl;
        for(int j=0;j<x[xx].size();j++)
            if(x[xx][j]!=yy){
                num+=y[x[xx][j]].size();
                num-=checkyx[mp(x[xx][j],xx)];//[x[xx][j]+L][xx+L];
            }
        
        for(int j=0;j<y[yy].size();j++)
            if(y[yy][j]!=xx){
                num+=x[y[yy][j]].size();
                num-=checkxy[mp(y[yy][j],yy)];//[y[yy][j]+L][yy+L];
            }
        cout<<num<<endl;//<<endl;
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