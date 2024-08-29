#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair


void solve()
{
    int n,k;
    cin>>n>>k;
    double sum=0;
    vector<int> a;
    for(int i=1,temp;i<=n;i++){
        cin>>temp;
        sum+=temp;
        a.push_back(temp);
        if(i>=k){
            if(sum/k>=1024)
                printf("%.6f MiBps\n",sum/k/1024);
            else
                printf("%.6f KiBps\n",sum/k);
            sum-=a[0];
            a.erase(a.begin());
        }
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