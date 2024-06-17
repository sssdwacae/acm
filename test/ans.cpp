#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve()
{
    int ans=0;
    int a[7];
    for(int i=1;i<=5;i++)
        cin>>a[i];

    int temp=0;
    
    temp=a[3]/2;
    ans+=temp;
    a[3]-=temp*2;

    temp=min(a[4],a[2]);
    ans+=temp;
    a[4]-=temp;a[2]-=temp;

    temp=min(a[5],a[1]);
    ans+=temp;
    a[5]-=temp;a[1]-=temp;
    if(a[5]){
        temp=min(a[5],a[2]);
        ans+=temp;
        a[5]-=temp;a[2]-=temp;

        if(a[5]){
            temp=min(a[5],a[3]);
            ans+=temp;
            a[5]-=temp;a[3]-=temp;

            if(a[5]){
                temp=min(a[5],a[4]);
                ans+=temp;
                a[5]-=temp;a[4]-=temp;

                if(a[5]){
                    temp=a[5]/2;
                    ans+=temp;
                    a[5]-=temp*2;
                }
            }
        }
    }

    temp=min(a[1]/2,a[4]);
    ans+=temp;
    a[4]-=temp;a[1]-=temp*2;

    if(a[4]){
        a[2]+=a[1];a[1]=0;
        temp=(a[2]/2,a[4]);
        ans+=temp;
        a[2]-=temp*2;a[4]-=temp;

        if(a[4]){
            a[3]+=a[2];a[2]=0;
            temp=(a[3]/2,a[4]);
            ans+=temp;
            a[3]-=temp*2;a[4]-=temp;

            if(a[4]){
                a[4]+=a[3];a[3]=0;
                temp=a[4]/3;
                ans+=temp;
                a[4]-=temp*3;
            }
        }
    }

    temp=min(a[3],min(a[2],a[1]));
    ans+=temp;
    a[3]-=temp;a[2]-=temp;a[1]-=temp;

    if(a[3]&&a[2]){
        temp=min(a[2]/2,a[3]);
        ans+=temp;
        a[2]-=temp*2;a[3]-=temp;
    }

    ans+=(a[1]+2*a[2]+3*a[3])/6;
    cout<<ans<<endl;
}

signed main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}