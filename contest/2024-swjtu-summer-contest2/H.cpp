#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

/*
1 1 2 3 4  //0
2 4 1 5 3 
 
1 1 2 3 4  //1
1 4 5
 
1 3 4      //2
1 4 5

1 3 4
2 5

2 4
2 5

2 4
5 

4
3




*/

void solve()
{
    vector<int> a,b;
    int cnta=0,cntb=0;
    int temp;
    for(int i=1;i<=5;i++){
        cin>>temp;
        // a.push_back(temp);
        cnta+=temp;
    }
    for(int j=1;j<=5;j++){
        cin>>temp;
        // b.push_back(temp);
        cntb+=temp;
    }
    if(cnta>=cntb)
        cout<<"Blue";
    else
        cout<<"Red";
    // bool flag=true;//ture a先减少b的
    // int cnt=0;
    // while(cnta!=0&&cntb!=0&&cnt<=20){
    //     cnt++;
    //      cout<<cnt<<' '<<cnta<<' '<<cntb<<'\n';
    //     sort(a.begin(),a.end());
    //     sort(b.begin(),b.end());
    //     int tb=b[0]/cnta;  //杀死b需要的时间
    //     if(b[0]%cnta)
    //         tb++;

    //     int ta=a[0]/cntb;   //杀死a需要的时间
    //     if(a[0]%cntb)
    //         ta++;

    //     if(flag){//a先手
    //         if(ta<tb){//ta先死
    //             b[0]-=(ta-1)*cnta;//a造成的伤害

    //             int sum=ta*cntb;//b造成的伤害
    //             while(sum){
    //                 if(a[0]<=sum){
    //                     cnta--;
    //                     if(cnta==0){
    //                         break;
    //                     }
    //                     sum-=a[0];
    //                     a.erase(a.begin());
    //                 }
    //                 else{
    //                     a[0]-=sum;
    //                     sum=0;
    //                 }
    //             }
    //         }
    //         else{ //tb先死
    //             flag=false;

    //             a[0]-=(tb-1)*cntb; //b造成的伤害

    //             int sum=tb*cnta;
    //             while(sum){
    //                 if(b[0]<=sum){
    //                     cntb--;
    //                     if(cntb==0){
    //                         break;
    //                     }
    //                     sum-=b[0];
    //                     b.erase(b.begin());
    //                 }
    //                 else{
    //                     b[0]-=sum;
    //                     sum=0;
    //                 }
    //             }
    //         }
    //     }
    //     else{//b先手
    //         if(tb<ta){//tb先死
    //             a[0]-=(tb-1)*cntb;//b造成的伤害

    //             int sum=tb*cnta;//a造成的伤害
    //             while(sum){
    //                 if(b[0]<=sum){
    //                     cntb--;
    //                     if(cntb==0){
    //                         break;
    //                     }
    //                     sum-=b[0];
    //                     b.erase(b.begin());
    //                 }
    //                 else{
    //                     b[0]-=sum;
    //                     sum=0;
    //                 }
    //             }

    //         }
    //         else{ //ta先死
    //             flag=true;

    //             b[0]-=(ta-1)*cnta; //a造成的伤害

    //             int sum=ta*cntb;
    //             while(sum){
    //                 if(a[0]<=sum){
    //                     cnta--;
    //                     if(cnta==0){
    //                         break;
    //                     }
    //                     sum-=a[0];
    //                     a.erase(a.begin());
    //                 }
    //                 else{
    //                     a[0]-=sum;
    //                     sum=0;
    //                 }
    //             }
    //         }
    //     }
    // }
    // if(cnta==0){
    //     cout<<"Red";
    // }
    // else{
    //     cout<<"Blue";
    // }
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