#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

// const int N=1e5+5;
#define int long long
#define mp make_pair

const int N=25;
int v[25][25][25];

int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    if(a>20||b>20||c>20)       
        return w(20,20,20);
    if(a<b&&b<c){
        int temp=0;
        if(v[a][b][c-1]==0){
            v[a][b][c-1]=w(a,b,c-1);
        }
        // temp+=v[a][b][c-1];

        if(v[a][b-1][c-1]==0){
            v[a][b-1][c-1]=w(a,b-1,c-1);
        }
        // temp+=;

        if(v[a][b-1][c]==0){
            v[a][b-1][c]=w(a,b-1,c);
        }
        // temp-=;
        v[a][b][c]=v[a][b][c-1]+v[a][b-1][c-1]-v[a][b-1][c];
    }
    else{
        
        if(v[a-1][b][c]==0){
            v[a-1][b][c]=w(a-1,b,c);
        }

        if(v[a-1][b-1][c]==0){
            v[a-1][b-1][c]=w(a-1,b-1,c);
        }

        if(v[a-1][b][c-1]==0){
            v[a-1][b][c-1]=w(a-1,b,c-1);
        }
        
        if(v[a-1][b-1][c-1]==0){
            v[a-1][b-1][c-1]=w(a-1,b-1,c-1);
        }
        v[a][b][c]=v[a-1][b][c]+v[a-1][b-1][c]+v[a-1][b][c-1]-v[a-1][b-1][c-1];
    }
    return  v[a][b][c];
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    while(1){ 
        if(a==-1&&b==-1&&c==-1)
            break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
        cin>>a>>b>>c;
    }
    return;
}

signed main()
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