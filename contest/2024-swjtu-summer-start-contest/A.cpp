#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

const int M=805;
int a[M][M],b[M][M],c[M][M],d[M][M],e[M][M];
int n,m;

void TLE();

bool check(int num)
{
    // memset(b,0,sizeof(b));
    // memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(a[i][j]>num)
                b[i][j]=1;
            else
                b[i][j]=0;
            if(a[i][j]==num)
                d[i][j]=1;
            else
                d[i][j]=0;
            c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+b[i][j];
            e[i][j]=e[i-1][j]+e[i][j-1]-e[i-1][j-1]+d[i][j];
        }
    if(num==6){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<b[i][j]<<' ';cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<d[i][j]<<' ';cout<<endl;
        }
    }
    for(int i=1;i<=n-m+1;i++)
        for(int j=1;j<=n-m+1;j++){
            if(c[i+m-1][j+m-1]-c[i-1][j+m-1]-c[i+m-1][j-1]+c[i-1][j-1]==(m*m+1)/2
                ||(c[i+m-1][j+m-1]-c[i-1][j+m-1]-c[i+m-1][j-1]+c[i-1][j-1]<(m*m+1)/2&&
                e[i+m-1][j+m-1]-e[i-1][j+m-1]-e[i+m-1][j-1]+e[i-1][j-1]+
                c[i+m-1][j+m-1]-c[i-1][j+m-1]-c[i+m-1][j-1]+c[i-1][j-1]>=(m*m+1)/2)
            )
                return true;
        }
    return false;
}

void solve()
{
    cin>>n>>m;
    int right=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            right=max(right,a[i][j]);
        }
    int left=0,mid;
    while(left<right){
        cout<<mid<<"????"<<check(mid)<<endl;
        cout<<left<<' '<<right<<endl;
        mid=(left+right+1)/2;
        if(check(mid))
            left=mid;
        else
            right=mid-1;
    }
    while(check(left))
        left--;
    // cout<<check(6)<<endl;
    cout<<left<<endl;
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

void TLE()
{
    int m,n;
    int ans=1e9+7;
    cin>>n>>m;
    int d=m*m-(m*m)/2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    // cout<<d<<endl;
    vector<int> v1,v2;
    map<int,int> m1,m2;
    if(n!=m){
        for(int i=1;i<=100;i++){
            int k=rand()%(n-m+1)+1;
            if(m1[k]==0){
                v1.push_back(k);
                m1[k]++;
            }
        }
        for(int j=1;j<=100;j++){
            int k=rand()%(n-m+1)+1;
            if(m2[k]==0){
                v2.push_back(k);
                m2[k]++;
            }
        }
    }
    else{
        v1.push_back(1);
        v2.push_back(1);
    }
    //for(int i=1;i+m-1<=n;i++)
    //    for(int j=1;j+m-1<=n;j++){
    for(int i=0;i<v1.size();i++)
        for(int j=0;j<v2.size();j++){
            // cout<<i<<' '<<j<<endl;
            vector<int> temp;
            for(int q=v1[i];q<=v1[i]+m-1;q++)
                for(int p=v2[j];p<=v2[j]+m-1;p++)   
                    temp.push_back(a[q][p]);
            sort(temp.begin(),temp.end());
            // cout<<temp.size();
            ans=min(ans,temp[d-1]);
        }
    cout<<ans;
    return;
}
