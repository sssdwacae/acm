#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long


const double eps =1e-8;
const double PI=acos(-1.0);

int sgn(double x)
{
    //平行 
    if(fabs(x)<eps)
        return 0;
    //相交方向
    if(x<0)
        return -1;
    else
        return 1;
}


struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;y=_y;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    }

    
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e){
        s=_s;e=_e;
    }
};

bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <=0 ;
}

void solve()
{
    int x,y,r,vx,vy,x1,y1,x2,y2;
    cin>>x>>y>>r>>vx>>vy>>x1>>y1>>x2>>y2;
    int temp=2e6/max(fabs(vx),fabs(vy));
    Point s(x,y),e(x+temp*vx,y+temp*vy);
    Line run(s,e);
    x1+=r;y1+=r;x2-=r;y2-=r;

    if(x1>x2||y1>y2){
        cout<<"No\n";
        return;
    }

    Point a1(x1,y2),a2(x2,y2),a3(x1,y1),a4(x2,y1);
    Line l1(a1,a2),l2(a1,a3),l3(a3,a4),l4(a2,a4);

    if(inter(run,l1)||inter(run,l2)||inter(run,l3)||inter(run,l4))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return;
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

/*
void solve()
{
    int x,y,r,vx,vy,x1,y1,x2,y2;
    cin>>x>>y>>r>>vx>>vy>>x1>>y1>>x2>>y2;
    //以x,y为原点
    x1=x1-x;x2=x2-x;y1=y1-y;y2=y2-y;
    //点在矩形内
    x1+=r;y1+=r;x2-=r;y2-=r;
    if(0<=x2&&0<=y2&&0>=x1&&0>=y1){
        cout<<"Yes\n";
        return;
    }
    //裁剪矩形
    if(vx>0&&x1<0)
        x1=0;
    else if(vx<0&&x2>0)
        x2=0;
    if(vy>0&&y1<0)
        y1=0;
    else if(vy<0&&y2>0)
        y2=0;
    if(x1>x2||y1>y2){
        cout<<"No\n";
        return;
    }
    //四条坐标轴
    if(vx==0){
        if(( (vy>0&&y2>0)||(vy<0&&y1<0) )&&x1<=0&&x2>=0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return;
    }
    if(vy==0){
        if(( (vx>0&&x2>0)||(vx<0&&x1<0) )&&y1<=0&&y2>=0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return;
    }
    if(   (vx>0&&vy>0&&x2>0&&y2>0&&((y1*vx<=vy*x1&&vy*x1<=y2*vx)||(x1*vy<=vx*y1&&vx*y1<=x2*vy)))
        ||(vx>0&&vy<0&&x2>0&&y1<0&&((vx*y1<=vy*x1&&vy*x1<=vx*y2)||(x2*vy<=vx*y2&&vx*y2<=x1*vy)))
        ||(vx<0&&vy<0&&x1<0&&y1<0&&((y2*vx<=vy*x2&&vy*x2<=y1*vx)||(x2*vy<=vx*y2&&vx*y2<=x1*vy)))
        ||(vx<0&&vy>0&&x1<0&&y2>0&&((vx*y2<=vy*x2&&vy*x2<=vx*y1)||(x1*vy<=vx*y1&&vx*y1<=x2*vy)))
        ){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    return;
}
*/