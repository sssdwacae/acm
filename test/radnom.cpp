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
    int TT=random(1e2)+1;
    int T=random(1e1)+2;
    cout<<T<<' '<<TT<<endl;
    for(int i=1;i<=T;i++){
        int x1,x2,y1,y2;
        int f=random(1e2)%2;
        if(f){
            x1=random(1e2)+1;
            y1=random(1e2)+1;
            y2=random(1e2)+1;
            x2=x1;
        }
        else{
            x1=random(1e2)+1;
            x2=random(1e2)+1;
            y1=random(1e2)+1;
            y2=y1;
        }
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }
    return 0;
}