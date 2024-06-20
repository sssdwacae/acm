#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
struct tangle{
    int x1,y1,x2,y2;
    tangle(){}
    tangle(int _x1,int _y1,int _x2,int _y2){
        x1=_x1;y1=_y1;x2=_x2;y2=_y2;
    }
};

struct point{
    int x,y;
    point(){}
    point(int _x,int _y){
        x=_x;y=_y;
    }
};

/*
假设两矩形的宽高分别是 w1，h1，w2，h2。

分别计算两个矩形的中心点 O1，O2，以及 O1 和 O2 之间的水平距离（w）和竖直距离（h）。

若2* w < w1 + w2  且 2* h <  h1 + h2 ，则两个矩形相交，否则不相交。
*/
bool check_tangle(tangle a,tangle b)//相交返回true
{
    return fabs(a.x1+a.x2-b.x1-b.x2) < a.x2-a.x1+b.x2-b.x1 
        && fabs(a.y1+a.y2-b.y1-b.y2) < a.y2-a.y1+b.y2-b.y1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,l,h;
    cin>>n>>l>>h;
    //被激活的坐标
    vector<int> px,py;
    px.push_back(0);
    py.push_back(0);
    //已经存放了的矩形
    vector<tangle> b;
    for(int i=1,_l,_h;i<=n;i++){
        cin>>_l>>_h;
        bool flag=false;
        tangle temp;
        point P;
        for(int j=0;j<px.size()&&!flag;j++)
            for(int q=0;q<py.size()&&!flag;q++){
                //挑选第P个点
                P.x=px[j];P.y=py[q];
                if(P.x+_l>l||P.y+_h>h)
                    continue;
                bool check=true;
                //想要构成的新矩形
                temp=tangle(P.x,P.y,P.x+_l,P.y+_h);
                for(int k=0;k<(int)b.size()&&check;k++){//检查点P添加不会影响之前的矩形
                    if(check_tangle(temp,b[k])){//两个矩形相交
                        check=false;
                        break;
                    }
                }
                if(check==true)
                    flag=true;
            }

        if(!flag){
            cout<<-1<<endl;
        }
        else{
            cout<<P.x<<' '<<P.y<<endl;
            //放入新的矩形
            b.push_back(temp);
            px.push_back(temp.x2);
            py.push_back(temp.y2);
            sort(px.begin(),px.end());
            sort(py.begin(),py.end());
        }
    }
    return 0;
}