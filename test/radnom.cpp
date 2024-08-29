#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
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
    int T=random(20)+2;
    cout<<T<<endl;
    for(int i=1;i<=T;i++){
        int n=random(1e3)+1;
        printf("%d ",n);
    }
    cout<<endl;
    for(int i=1;i<=T;i++){
        int n=random(1e3)+1;
        if(i==1)
            cout<<0<<' ';
        else if(i==2)
            cout<<1<<' ';
        else
            printf("%d ",n%2);
    }
    return 0;
}