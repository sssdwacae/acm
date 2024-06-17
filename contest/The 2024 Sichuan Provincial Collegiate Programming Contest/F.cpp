#include<iostream>
#include<algorithm>
using namespace std;

void solve()
{
    int x,y,r,vx,vy,x1,y1,x2,y2;
    cin>>x>>y>>r>>vx>>vy>>x1>>y1>>x2>>y2;
    x1-=x;x2-=x;y1-=y;y2-=y;
    if(x!=0){
        double left=max((double)(x1+r),1.0*(y1+r)*vx/vy);
        double right=min((double)x2-r,1.0*(y2-r)*vx/vy);
        if(left<=right)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    else{
        if(y2-y1>=2*r&&x1<=-r&&x2>=r)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}