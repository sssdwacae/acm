#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int n,m;
#define mp make_pair
void solve()
{
    cin>>n>>m;
    vector<string> s(n+1);
    vector<int> ttt(m+1,0);
    vector<vector<int> > a(n+1,ttt);
    vector<vector<int> > check(n+1,ttt);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int cnt=1;
    int x=1,y=1;
    int nx=1,ny=1;
    check[x][y]=2;
    bool huan=false;
    
    while(1){
        if(s[x][y]=='u'){//上
            nx=x-a[x][y];
            ny=y;
        }
        else if(s[x][y]=='d'){//下
            nx=x+a[x][y];
            ny=y;
        }
        else if(s[x][y]=='l'){//左
            ny=y-a[x][y];
            nx=x;
        }
        else if(s[x][y]=='r'){//右
            ny=y+a[x][y];
            nx=x;
        }
        if(nx<1||nx>n||ny<1||ny>m){
            if(cnt==n*m){
                cout<<"Yes\n";
                return;
            }
            break;
        }
        if(check[nx][ny]){
            if(cnt==n*m){
                cout<<"Yes\n";
                return;
            }
            break;
        }
        x=nx;
        y=ny;
        check[x][y]=2;//走了
        cnt++;
    }
    if(nx==1&&ny==1)//走成了环
        huan=true;
    int prex=1,prey=1;//前一次链条的起点，也就是下一次的终点
    vector<pair<int,int> > mid;//还没有走过的点
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!check[i][j])
                mid.push_back(mp(i,j));

    if(huan){
        //找一个新点x,y作为起点，xmid，ymid存储
        for(int i=0;i<(int)mid.size();i++)
            if(check[mid[i].first][mid[i].second]==0){
                x=mid[i].first;
                y=mid[i].second;
                break;
            }
        prex=x,prey=y;//新链的起点
        
        ny=y;nx=x;
        check[x][y]=1;
        cnt++;
        //走新起点
        while(1){
            if(s[x][y]=='u'){//上
                nx=x-a[x][y];
                ny=y;
            }
            else if(s[x][y]=='d'){//下
                nx=x+a[x][y];
                ny=y;
            }
            else if(s[x][y]=='l'){//左
                ny=y-a[x][y];
                nx=x;
            }
            else if(s[x][y]=='r'){//右
                ny=y+a[x][y];
                nx=x;
            }
            if(nx<1||nx>n||ny<1||ny>m){//环只能走进
                cout<<"No\n";
                return;
            }
            if(check[nx][ny]==1){
                cout<<"No\n";
                return;
            }
//必须走进之前的环
            if(check[nx][ny]==2){
                break;
            }
            x=nx;
            y=ny;
            check[x][y]=1;//走了
            cnt++;
        }
    }
//前一个的点是prex，prey

    while(cnt<n*m){
        //找一个新点开始走
        for(int i=0;i<(int)mid.size();i++)
            if(check[mid[i].first][mid[i].second]==0){
                x=mid[i].first;
                y=mid[i].second;
                break;
            }
        //存储新起点
        int xmid=x,ymid=y;
        nx=x;ny=y;
        check[xmid][ymid]=1;
        cnt++;
        while(1){
            if(s[x][y]=='u'){//上
                nx=x-a[x][y];
                ny=y;
            }
            else if(s[x][y]=='d'){//下
                nx=x+a[x][y];
                ny=y;
            }
            else if(s[x][y]=='l'){//左
                ny=y-a[x][y];
                nx=x;
            }
            else if(s[x][y]=='r'){//右
                ny=y+a[x][y];
                nx=x;
            }
            if(nx<1||nx>n||ny<1||ny>m){
                cout<<"No\n";
                return;
            }
            if(check[nx][ny]){
                if(nx!=prex||ny!=prey){
                    cout<<"No\n";
                    return;
                }
                break;
            }
            x=nx;
            y=ny;
            check[x][y]=1;//走了
            cnt++;
        }
        prex=xmid;
        prey=ymid;
    }


    if(cnt==n*m)
        cout<<"Yes\n";
    else
        cout<<"No\n";
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