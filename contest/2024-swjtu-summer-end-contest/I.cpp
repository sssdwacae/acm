#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int a[4][4],check[4][4];//5 T  2A

bool dfs(int pos)//第几步  T 的状态
{
    if(pos==10){
        int numa=0,numb=0;
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++){
                if(check[i][j]==5)
                    numa+=a[i][j];
                else
                    numb+=a[i][j];
            }
        if(numa>numb)
            return true;
        else 
            return false;
    }
    else if(pos&1){//T在走
        // bool flag=false;
        //必走
        for(int i=1;i<=3;i++){
            int num=0;
            for(int j=1;j<=3;j++){
                num+=check[i][j];
            }
            if(num==4){
                for(int j=1;j<=3;j++)
                    if(check[i][j]==0){
                        check[i][j]=5;
                        bool temp=dfs(pos+1);
                        check[i][j]=0;
                        return temp;
                        // return;
                    }
            }
        }

        for(int j=1;j<=3;j++){
            int num=0;
            for(int i=1;i<=3;i++){
                num+=check[i][j];
            }
            if(num==4){
                for(int i=1;i<=3;i++)
                    if(check[i][j]==0){
                        check[i][j]=5;
                        bool temp=dfs(pos+1);
                        check[i][j]=0;
                        return temp;
                    }
            }
        }

        if(check[1][1]+check[2][2]+check[3][3]==4){
            if(check[1][1]==0){
                check[1][1]=5;
                bool temp=dfs(pos+1);
                check[1][1]=0;
                return temp;
            }
            else if(check[2][2]==0){
                check[2][2]=5;
                bool temp=dfs(pos+1);
                check[2][2]=0;
                return temp;
            }
            else{
                check[3][3]=5;
                bool temp=dfs(pos+1);
                check[3][3]=0;
                return temp;
            }
        }
        if(check[1][3]+check[2][2]+check[3][1]==4){
            if(check[1][3]==0){
                check[1][3]=5;
                bool temp=dfs(pos+1);
                check[1][3]=0;
                return temp;
            }
            else if(check[2][2]==0){
                check[2][2]=5;
                bool temp=dfs(pos+1);
                check[2][2]=0;
                return temp;
            }
            else{
                check[3][1]=5;
                bool temp=dfs(pos+1);
                check[3][1]=0;
                return temp;
            }
        }
        //随机走
        // bool flag=false;//此次必赢
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                if(check[i][j]==0){
                    check[i][j]=5;
                    bool temp=dfs(pos+1);
                    check[i][j]=0;
                    if(temp)//对于T来说，下次全赢，才能赢
                        return true;// flag=true;
                }
        return false;
        // return flag;
    }
    else{//A在走
        for(int i=1;i<=3;i++){
            int num=0;
            for(int j=1;j<=3;j++){
                num+=check[i][j];
            }
            if(num==10){
                for(int j=1;j<=3;j++)
                    if(check[i][j]==0){
                        check[i][j]=2;
                        bool temp=dfs(pos+1);
                        check[i][j]=0;
                        return temp;
                        // return;
                    }
            }
        }

        for(int j=1;j<=3;j++){
            int num=0;
            for(int i=1;i<=3;i++){
                num+=check[i][j];
            }
            if(num==10){
                for(int i=1;i<=3;i++)
                    if(check[i][j]==0){
                        check[i][j]=2;
                        bool temp=dfs(pos+1);
                        check[i][j]=0;
                        return temp;
                    }
            }
        }

        if(check[1][1]+check[2][2]+check[3][3]==10){
            if(check[1][1]==0){
                check[1][1]=2;
                bool temp=dfs(pos+1);
                check[1][1]=0;
                return temp;
            }
            else if(check[2][2]==0){
                check[2][2]=2;
                bool temp=dfs(pos+1);
                check[2][2]=0;
                return temp;
            }
            else{
                check[3][3]=2;
                bool temp=dfs(pos+1);
                check[3][3]=0;
                return temp;
            }
        }
        if(check[1][3]+check[2][2]+check[3][1]==10){
            if(check[1][3]==0){
                check[1][3]=2;
                bool temp=dfs(pos+1);
                check[1][3]=0;
                return temp;
            }
            else if(check[2][2]==0){
                check[2][2]=2;
                bool temp=dfs(pos+1);
                check[2][2]=0;
                return temp;
            }
            else{
                check[3][1]=2;
                bool temp=dfs(pos+1);
                check[3][1]=0;
                return temp;
            }
        }
        //随机走
        // bool flag=true;//此次必赢
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                if(check[i][j]==0){
                    check[i][j]=2;
                    bool temp=dfs(pos+1);
                    check[i][j]=0;
                    if(!temp)//下次全赢，才能赢
                        return temp;// flag=false;
                    // check[i][j]=0;
                }
        return true;
    }
}

void solve()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>a[i][j];
    if(dfs(1))
        cout<<"Takahashi";
    else
        cout<<"Aoki";
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