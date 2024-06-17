#include<iostream>
#include<algorithm>
using namespace std;

void solve()
{
    int x,y,r,vx,vy,x1,y1,x2,y2;
    cin>>x>>y>>r>>vx>>vy>>x1>>y1>>x2>>y2;
    x1-=x;x2-=x;y1-=y;y2-=y;
    if(vx!=0){
        if(vy!=0){
            double left,right;
            if(vx*vy>0){
                left=max((double)(x1+r),1.0*(y1+r)*vx/vy);
                right=min((double)x2-r,1.0*(y2-r)*vx/vy);
            }
            else{
                left=max((double)(x1+r),1.0*(y2-r)*vx/vy);
                right=min((double)x2-r,1.0*(y1+r)*vx/vy);
            }
            if(vx>0)
                left=0;
            else
                right=0;
            //cout<<left<<' '<<right<<endl;
            if(left<=right)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else{
            if((vx>0&&(x2-max(x1,0)>=2*r)||(vx<0&&(min(x2,0)-x1>=2*r)))&&y1<=-r&&y2>=r)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        

    }
    else{
        if((vy>0&&(y2-max(y1,0)>=2*r)||(vy<0&&(min(y2,0)-y1>=2*r)))&&x1<=-r&&x2>=r)
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