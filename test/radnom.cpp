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
    int T=random(1e1)+1;
    cout<<T<<endl;
    for(int i=1;i<=T;i++){
        int n=random(5)+1;
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            int l=random(1e2)+1;
            int r=random(1e2)+l;
            cout<<l<<' '<<r<<endl;
        }
    }
    return 0;
}