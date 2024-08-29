#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    int left=1,right=n;
    int a,b;
    cout<<"? 1\n";
    cout.flush();
    cin>>a;
    cout<<"? "<<n<<endl;
    cout.flush();
    cin>>b;
    while(left+1<right){
        int mid=(left+right)/2;
        int c;
        cout<<"? "<<mid<<endl;
        cout.flush();
        cin>>c;
        int s=a+b-(left-right);

        if(c==s/2){//找到
            int temp1,temp2;
            cout<<"? "<<mid+1<<endl;
            cout.flush();
            cin>>temp1;
            cout<<"? "<<mid-1<<endl;
            cout.flush();
            if(temp1>temp2){
                cout<<"! "<<(mid+1+n+1)%(n+1)<<' '<<(mid+a-temp1-1+n+1)%(n+1)<<endl;
                cout<<temp1<<' '<<temp2<<endl;
                cout.flush();
                return;
            }
            else{
                cout<<"! "<<(mid-1+n)%(n)<<' '<<(mid-a+temp2+1+n)%(n)<<endl;
                cout<<temp1<<' '<<temp2<<endl;
                return;
            }
        }
        else if(c<s/2){
            right=mid;
            b=c;
        }
        else{
            left=mid;
            a=c;
        }
    }
    // cout<<"! "<<left<<' '<<right<<endl;
    // cout.flush();
    return;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}