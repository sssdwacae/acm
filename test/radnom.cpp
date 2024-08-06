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
    int T=1;
    cout<<T<<endl;
    for(int i=1;i<=T;i++){
        int m=random(1e2);
        int k=random(1e2);
        int h=random(1e3);
        cout<<m<<' '<<k<<' '<<h<<endl;
    }
    return 0;
}