#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve()
{
    int x,y,r,vx,vy,x1,y1,x2,y2;
    cin>>x>>y>>r>>vx>>vy>>x1>>y1>>x2>>y2;

    //以x,y为原点
    x1=x1-x;x2=x2-x;y1=y1-y;y2=y2-y;

    //cout<<"first:"<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;

    //点在矩形内
    x1+=r;y1+=r;x2-=r;y2-=r;

    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;

    if(0<=x2&&0<=y2&&0>=x1&&0>=y1){
        cout<<"Yes\n";
        return;
    }

    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;

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
        ||(vx<0&&vy<0&&x1<0&&y1<0&&((x2*vy<=vy*x2&&vy*x2<=x1*vx)||(y2*vy<=vx*y2&&vx*y2<=y1*vy)))
        ||(vx<0&&vy>0&&x1<0&&y2>0&&((vx*y1<=vy*x2&&vy*x2<=vx*y2)||(x1*vy<=vx*y1&&vx*y1<=x2*vy)))
        ){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    return;
}

signed main()
{
    freopen("in.txt","r",stdin);
    freopen("ansout.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cout<<T;
        solve();
    }
    return 0;
}