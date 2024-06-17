#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

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
        int a[5];
        for(int j=0;j<5;j++)
            a[j]=random(1e9);
        for(int j=0;j<5;j++)
            cout<<a[j]<<' ';
        cout<<endl;
    }
    return 0;
}