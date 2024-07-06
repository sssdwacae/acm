#include<iostream>
using namespace std;

#define endl '\n'

// priority_queue<int> q;

const int N=5e5+5;
//#define ll long long
//#define mp make_pair

int n,m;
int dian[N];
void solve()
{
    int l=1,r=1;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x;
        if(x==1){
            dian[l]=1;
            l++;
        }
        else if(x==2){
            cin>>y;
            dian[y]--;
        }
        else if(x==3){
            while(dian[r]<=0){
                // cout<<":"<<r<<endl;
                r++;
            }
            cout<<r<<endl;
            //dian[r]=0;
        }
    }

    return;
}

int  main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}