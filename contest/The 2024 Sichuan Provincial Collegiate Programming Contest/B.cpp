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
    // for(int i=1;i<=5;i++)
    //     cout<<a[i]<<' ';cout<<endl;
    ans+=(a[1]+2*a[2]+3*a[3])/6;
    cout<<ans<<endl;
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

/*
void slove()
{
    int a[10];
    int sum=0;
    for(int i=1;i<=5;i++){
        cin>>a[i];
        sum+=a[i]*i;
    }
    int ans=0;

    int temp=min(a[1],a[5]);
    ans+=temp;
    a[1]-=temp;a[5]-=temp;

    if(a[5]==0){
        temp=a[3]/2;
        ans+=temp;
        a[3]-=temp*2;

        temp=min(a[2],a[4]);
        ans+=temp;
        a[2]-=temp;a[4]-=temp;

        if(a[2]==0){
            temp=min(a[1]/2,a[4]);
            ans+=temp;
            a[1]-=temp*2;a[4]-=temp;

            if(a[1]==0){
                a[4]+=a[3];a[3]=0;
                temp=a[4]/3;
                ans+=temp;
                a[4]-=temp*3;
            }
            else if(a[4]==0){
                if(a[1]>=3&&a[3]){
                    ans++;
                    a[3]=0;a[1]-=3;
                }
                if(a[3]){
                    a[1]++;
                    a[3]--;
                }
                temp=a[1]/6;
                ans+=temp;
                a[1]-=temp*6;
            }
            if(a[1]>=2){
                temp=min(a[1]/2,a[4]);
                ans+=temp;
                a[1]-=temp*2;a[4]-=temp;
            }
            if(a[1]==1){
                a[4]+=1;a[1]--;
            }
            if(a[3]){
                a[4]++;
                a[3]--;
            }
            temp=a[4]/3;
            ans+=temp;
            a[4]-=temp*3;
        }
        else if(a[4]==0){
            temp=min(min(a[1],a[2]),a[3]);
            ans+=temp;
            a[1]-=temp;a[2]-=temp;a[3]-=temp;
            if(a[1]==0){
                temp=a[3]/2;
                ans+=temp;
                a[3]-=temp*2;

                if(a[3]){
                    a[2]++;
                    a[3]--;
                }

                temp=a[2]/3;
                ans+=temp;
                a[2]-=temp*3;


            }
            else if(a[2]==0){
                if(a[1]>=3&&a[3]){
                    ans++;
                    a[3]=0;
                    a[1]-=3;
                }
                temp=a[1]/6;
                ans+=temp;
                a[1]-=temp*6;
            }
            else if(a[3]==0){
                temp=a[2]/3;
                ans+=temp;
                a[2]-=temp*3;
                if(a[2]==2){
                    if(a[1]>=2){
                        ans++;
                        a[1]-=2;
                    }
                }
                else if(a[2]==1){
                    if(a[1]>=4){
                        ans++;
                        a[1]-=4;
                    }
                }
                ans+=a[1]/6;
            }
        }
    }
    else if(a[1]==0){
        temp=a[3]/2;
        ans+=temp;
        a[3]-=temp*2;

        temp=min(a[2],a[4]);
        ans+=temp;
        a[2]-=temp;a[4]-=temp;

        temp=min(a[2],a[5]);
        ans+=temp;
        a[2]-=temp;a[5]-=temp;

        if(a[2]==0){
            temp=min(a[3],a[5]);
            ans+=temp;
            a[3]-=temp;a[5]-=temp;
            if(a[3]==0){
                temp=min(a[4],a[5]);
                ans+=temp;
                a[4]-=temp;a[5]-=temp;
                if(a[4]==0){
                    temp=a[5]/2;
                    ans+=temp;
                    a[5]-=temp*2;
                    // ans+=a[5]/2;
                }
                else if(a[5]==0){
                    temp=a[4]/3;
                    ans+=temp;
                    a[4]-=temp*3;
                    // ans+=a[4]/3;
                }
            }
            else if(a[5]==0){
                temp=a[3]/2;
                ans+=temp;
                a[3]-=temp*2;
                if(a[3]!=0){
                    if(a[4]>=2){
                        a[4]-=2;
                        ans++;
                    }
                }
                temp=a[4]/3;
                ans+=temp;
                a[4]-=temp*3;
            }   
        }
        else if(a[5]==0){
            temp=min(a[2],a[4]);
            ans+=temp;
            a[2]-=temp;a[4]-=temp;
            if(a[2]==0){
                temp=a[3]/2;
                ans+=temp;
                a[3]-=temp*2;
                if(a[3]!=0){
                    if(a[4]>=2){
                        a[4]-=2;
                        ans++;
                        a[3]--;
                    }
                }
                temp=a[4]/3;
                ans+=temp;
                a[4]-=temp*3;
            }
            else if(a[4]==0){
                temp=a[3]/2;
                ans+=temp;
                a[3]-=temp*2;

                if(a[3]){
                    a[3]--;
                    a[2]++;
                } 
                temp=a[2]/3;
                ans+=temp;
                a[2]-=temp*3;
            }
        }
    }
    
    //ans=min(ans,sum/6);
    cout<<ans<<endl;
    return;
}
*/