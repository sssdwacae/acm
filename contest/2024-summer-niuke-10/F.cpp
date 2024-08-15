#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
};

int gcd(int a, int b)
{ 
    return b == 0 ? a : gcd(b, a % b); 
}

void solve()
{
    int n;
    cin>>n;
    vector<int> temp(n+1,0);
    vector<vector<int> > check(n+1,temp);
    vector<Point> p;
    for(int i=1,x,y;i<=n*n;i++){
        cin>>x>>y;
        if(check[x][y]==0){
            check[x][y]=1;
            for(int i=0;i<p.size();i++){
                int sx=x,sy=y,ex=p[i].x,ey=p[i].y;
                if(sx>ex){
                    swap(sx,ex);
                    swap(sy,ey);
                }
                int dx=ex-sx,dy=ey-sy;
                int g=gcd((int)fabs(dx),(int)fabs(dy));
                dx/=g;dy/=g;

                int nx=x,ny=y;
                while(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                    nx+=dx;ny+=dy;
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
                        check[nx][ny]=1;
                }
                nx=x,ny=y;
                while(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                    nx-=dx;ny-=dy;
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
                        check[nx][ny]=1;
                }


            }
            p.push_back(Point(x,y));
            cout<<1;
        }
        else
            cout<<0;
    }
    return;
}

signed main()
{
    // freopen("in.txt","r",stdin);
    // freopen("ansout.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}