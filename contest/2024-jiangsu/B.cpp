#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair
#define sqrt sqrtl
// #define double long double

const double eps =1e-8;
const double PI=acos(-1.0);
// const double PI=3.1415926535;

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
    //减法重载
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    //叉乘
    double operator ^(const Point &b)const{
        return x*b.y-y*b.x;
    }
    //点乘
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    } 
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else 
                return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};

double q_q(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double o_o(Point a,Point b,Point c)
{
    double A=q_q(a,b),B=q_q(a,c),C=q_q(b,c);
    double P=(A+B+C)/2.0;
    return sqrt(P*(P-A)*(P-C)*(P-B));  
}

double s_s(Point t,Point s,Point o,double th,double r)
{
    double sum=1.0*PI*r*r*th/360;
    Point O(0,0);
    sum-=r*r/2*sin(th*PI/180.0);
    // sum-=o_o(O,s,t);
    sum+=o_o(s,o,t);
    return sum;
    // return o_o(s,o,t)+r*r/2.0*(th*PI/180.0-sin(th*PI/180.0));
}

void solve()
{
    int s[7],t[6];
    Point S[7],T[6];
    double r;
    cin>>r;
    for(int i=1;i<=5;i++){
        cin>>s[i];
        S[i].x=1.0*r*cos(2.0*PI*s[i]/360);
        S[i].y=1.0*r*sin(2.0*PI*s[i]/360);
    }
    S[6]=S[1];
    s[6]=s[1];
    for(int i=1;i<=5;i++){
        cin>>t[i];
        T[i].x=r*cos(2.0*PI*t[i]/360);
        T[i].y=r*sin(2.0*PI*t[i]/360);
    }
    Point o[6];
    o[1]=(Line(T[1],S[3])&Line(S[2],T[5])).second;
    o[2]=(Line(T[2],S[4])&Line(T[1],S[3])).second;
    o[3]=(Line(T[3],S[5])&Line(T[2],S[4])).second;
    o[4]=(Line(T[4],S[1])&Line(T[3],S[5])).second;
    o[5]=(Line(T[5],S[2])&Line(S[1],T[4])).second;
    double sum=PI*r*r;
    for(int i=1;i<=5;i++){
        double th=s[i+1]-t[i];
        if(th<0)
            th+=360;
        sum-=1.0*s_s(T[i],S[i+1],o[i],th,r);
    }
    printf("%.9lf\n",sum);
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