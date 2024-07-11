#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

struct Point
{
    int x,y,z;
    Point(){}
    Point(double _x,double _y){
        x=_x;y=_y;
    }  
};

void solve()
{
    vector<pair<pair<int,int>,int >> p(10);
    map<int,int> cnt;
    for(int i=1;i<=8;i++){
        int x,y,z;
        cin>>x>>y>>z;
        p[i]=mp(mp(x,y),z);
    }
    for(int i=1;i<=8;i++){
        for(int j=i+1;j<=8;j++){
            int dx=p[i].first.first-p[j].first.first;
            int dy=p[i].first.second-p[j].first.second;
            int dz=p[i].second-p[j].second;
            int d=dx*dx+dy*dy+dz*dz;
            cnt[d]++;
        }
    }
    vector<pair<int,int> > mm(cnt.begin(),cnt.end());
    int ss=0;
    int cc=0;
    // for(int i=0;i<mm.size();i++){
    //     cout<<mm[i].first<<' '<<mm[i].second<<endl;
    // }
    for(int i=0;i<mm.size();i++)
        if(mm[i].second==12){
            ss++;
        }
        else if(mm[i].second==4){
            cc++;
        }
    if(cc==1&&ss==2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    // cout<<endl<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}