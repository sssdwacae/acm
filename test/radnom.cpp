#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define mx 2e6
#define mn 1e6

int random(int n)
{
    return (long long)rand()*rand()%n;
}

int main()
{
    freopen("in.txt","w",stdout);
    srand((unsigned)time(0));
    int T=random(1e4);
    cout<<T<<endl;
    for(int i=1;i<=T;i++){
        int x,y,vx,vy,r;
        x=random(mx)-mn;
        y=random(mx)-mn;
        r=random(mn);
        vx=random(mx)-mn;
        vy=random(mx)-mn;
        cout<<x<<' '<<y<<' '<<r<<' '<<vx<<' '<<vy;
        cout<<endl;
        int x1,x2,y1,y2;
        x1=random(mx)-mn;
        y1=random(mx)-mn;
        x2=x1+random(mn)+1;
        y2=y1+random(mn)+1;
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2;
        cout<<endl;
    }
    return 0;
}