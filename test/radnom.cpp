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
    int T=1;
    cout<<T<<endl;
    for(int i=1;i<=T;i++){
        int n=random(1e1)+2;
        cout<<n<<endl;
        vector<int> tt;
        for(int i=1;i<=n;i++){
            int temp=random(1e5)+1;
            tt.push_back(temp);
            //cout<<temp<<" ";
        }
        sort(tt.begin(),tt.end());
        for(int i=0;i<tt.size();i++)
            cout<<tt[i]<<' ';
        cout<<endl;
    }
    return 0;
}