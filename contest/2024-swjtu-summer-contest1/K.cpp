#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

int n,x,y;
vector<int> a1,a2;
int ap1[106],ap2[109];
int sum1[105],sum2[105];
bool FLAG1=false,FLAG2=false;
void dfs(bool flag,int pos,int num)
{
    
    if(flag){//y
        if(FLAG1){
            return;
        }
        if(pos==a1.size()&&num==y){
            FLAG1=true;
            return;//成立
        }
        else if(pos==a1.size()){
            return;
        }
        else if((num+sum1[n/2]-sum1[pos-1]<y&&y>=0||num-sum1[n/2]+sum1[pos-1]>y&&y<=0)&&n&1==0){
            return;
        }
        else if((num+sum1[(n+1)/2]-sum1[pos-1]<y&&y>=0||num-sum1[(n+1)/2]+sum1[pos-1]>y&&y<=0)&&n&1){
            return;
        }
        else if(pos==a1.size()-1&&num+a1[pos]!=y&&num-a1[pos]!=y){
            return;
        }
        else if(a1.size()>4){
            if(pos+4==a1.size()&&
                num+a1[pos]+a1[pos+1]+a1[pos+2]+a1[pos+3]!=y&&
                num+a1[pos]+a1[pos+1]+a1[pos+2]-a1[pos+3]!=y&&
                num+a1[pos]+a1[pos+1]-a1[pos+2]+a1[pos+3]!=y&&
                num+a1[pos]+a1[pos+1]-a1[pos+2]-a1[pos+3]!=y&&
                num+a1[pos]-a1[pos+1]+a1[pos+2]+a1[pos+3]!=y&&
                num+a1[pos]-a1[pos+1]+a1[pos+2]-a1[pos+3]!=y&&
                num+a1[pos]-a1[pos+1]-a1[pos+2]+a1[pos+3]!=y&&
                num+a1[pos]-a1[pos+1]-a1[pos+2]-a1[pos+3]!=y&&
                num-a1[pos]+a1[pos+1]+a1[pos+2]+a1[pos+3]!=y&&
                num-a1[pos]+a1[pos+1]+a1[pos+2]-a1[pos+3]!=y&&
                num-a1[pos]+a1[pos+1]-a1[pos+2]+a1[pos+3]!=y&&
                num-a1[pos]+a1[pos+1]-a1[pos+2]-a1[pos+3]!=y&&
                num-a1[pos]-a1[pos+1]+a1[pos+2]+a1[pos+3]!=y&&
                num-a1[pos]-a1[pos+1]+a1[pos+2]-a1[pos+3]!=y&&
                num-a1[pos]-a1[pos+1]-a1[pos+2]+a1[pos+3]!=y&&
                num-a1[pos]-a1[pos+1]-a1[pos+2]-a1[pos+3]!=y
                ){
                    return;
                }
        }

        ap1[pos]=1;
        dfs(flag,pos+1,num+a1[pos]);
        if(FLAG1){
            return;
        }
        ap1[pos]=0;


        ap1[pos]=2;
        dfs(flag,pos+1,num-a1[pos]);
        if(FLAG1){
            return;
        }
        ap1[pos]=0;
    }
    else{
        if(FLAG2){
            return;
        }
        if(pos==a2.size()&&num==x){
            FLAG2=true;
            return;//成立
        }
        else if(pos==a2.size()){
            return;
        }
        else if(num+sum2[n/2]-sum2[pos-1]<x&&x>=0||num-sum2[n/2]+sum2[pos-1]>x&&x<=0){
            return;
        }
        else if(pos==a2.size()-1&&num+a2[pos]!=x&&num-a2[pos]!=x){
            return;
        }
        else if(a2.size()>4){
            if(pos+4==a2.size()&&
                num+a2[pos]+a2[pos+1]+a2[pos+2]+a2[pos+3]!=x&&
                num+a2[pos]+a2[pos+1]+a2[pos+2]-a2[pos+3]!=x&&
                num+a2[pos]+a2[pos+1]-a2[pos+2]+a2[pos+3]!=x&&
                num+a2[pos]+a2[pos+1]-a2[pos+2]-a2[pos+3]!=x&&
                num+a2[pos]-a2[pos+1]+a2[pos+2]+a2[pos+3]!=x&&
                num+a2[pos]-a2[pos+1]+a2[pos+2]-a2[pos+3]!=x&&
                num+a2[pos]-a2[pos+1]-a2[pos+2]+a2[pos+3]!=x&&
                num+a2[pos]-a2[pos+1]-a2[pos+2]-a2[pos+3]!=x&&
                num-a2[pos]+a2[pos+1]+a2[pos+2]+a2[pos+3]!=x&&
                num-a2[pos]+a2[pos+1]+a2[pos+2]-a2[pos+3]!=x&&
                num-a2[pos]+a2[pos+1]-a2[pos+2]+a2[pos+3]!=x&&
                num-a2[pos]+a2[pos+1]-a2[pos+2]-a2[pos+3]!=x&&
                num-a2[pos]-a2[pos+1]+a2[pos+2]+a2[pos+3]!=x&&
                num-a2[pos]-a2[pos+1]+a2[pos+2]-a2[pos+3]!=x&&
                num-a2[pos]-a2[pos+1]-a2[pos+2]+a2[pos+3]!=x&&
                num-a2[pos]-a2[pos+1]-a2[pos+2]-a2[pos+3]!=x
                ){
                    return;
                }
        }

        ap2[pos]=1;
        dfs(flag,pos+1,num+a2[pos]);
        if(FLAG2){
            return;
        }
        ap2[pos]=0;

        ap2[pos]=2;
        dfs(flag,pos+1,num-a2[pos]);
        if(FLAG2){
            return;
        }
        ap2[pos]=0;
    }
    
}

void solve()
{
    cin>>n>>x>>y;
    a1.push_back(0);
    a2.push_back(0);
    int ss1=0,ss2=0;
    for(int i=1,temp;i<=n;i++){
        cin>>temp;
        
        if(i&1){
            sum1[(i+1)/2]=sum1[(i+1)/2-1]+temp;
            a1.push_back(temp);
            ss1+=temp;
        }
        else{    
            sum2[i/2]=sum2[i/2-1]+temp;
            a2.push_back(temp);
            ss2+=temp;
        }
    }
    // cout<<a1.size();
    // cout<<(long long)pow(2,20);
    // for(int i=0;i<a1.size();i++)
    //     cout<<a1[i]<<' '<<endl;
    // for(int i=0;i<a1.size();i++)
    //     cout<<a2[i]<<' '<<endl;
    if(x>ss2&&x>0||y>ss1&&y>0||x<-ss2&&x<0||y<-ss1&&y<0){
        cout<<"No";
        return;
    }
    dfs(1,1,0);
    dfs(0,1,0);
    if(FLAG2&&FLAG1){
        cout<<"Yes\n";
        // int temp1=1;//L+
        // int temp2=1;//R+
        //+1  -2
        // for(int i=1;i<=n/2;i++)
        //     cout<<ap1[i]<<' ';
        // cout<<endl;
        int temp=4;//U1D2L3R4
        
        for(int i=1;i<=n/2;i++){
            if(temp==4&&ap1[i]==1){
                cout<<'L';
                temp=1;
            }
            else if(temp==4){
                cout<<'R';
                temp=2;
            }
            else if(temp==3&&ap1[i]==1){
                cout<<"R";
                temp=1;
            }
            else{
                cout<<"L";
                temp=2;
            }

            if(temp==1&&ap2[i]==1){
                cout<<"R";
                temp=4;
            }
            else if(temp==1){
                cout<<"L";
                temp=3;
            }
            else if(temp==2&&ap2[i]==1){
                cout<<"L";
                temp=4;
            }
            else{
                cout<<"R";
                temp=3;
            }
        }
        if(n&1){
            int i=n/2+1;
            if(temp==4&&ap1[i]==1){
                cout<<'L';
                temp=1;
            }
            else if(temp==4){
                cout<<'R';
                temp=2;
            }
            else if(temp==3&&ap1[i]==1){
                cout<<"R";
                temp=1;
            }
            else{
                cout<<"L";
                temp=2;
            }
        }
    }
    else{
        cout<<"No";
        // if(FLAG1)
        //     cout<<"1true";
        // else if(FLAG2)
        //     cout<<"2true";
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