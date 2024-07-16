#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
// #define int long long
#define mp make_pair


int cnt=0;
int n, p, q, m;
unsigned int SA, SB, SC;
inline unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void gen()
{
    priority_queue<unsigned long long int> temp;
    cin>>n>>p>>q>>m>>SA>>SB>>SC;
    // scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    unsigned long long int ans=0;
    bool flag=false;
    for (unsigned long long int i = 1; i <= n; i++)
    {
        
        if (rng61() % (p + q) < p){
            // cout<<SA<<' '<<SB<<' '<<SC<<' '<<SC % (p + q)<<' '<<p<<endl;
            temp.push(rng61() % m + 1);
        }
        else{
            if(!temp.empty()){
                temp.pop();
            }
        }

        if(!flag&&!temp.empty()){
            ans=i*temp.top();
            flag=true;
        }
        else if(flag&&!temp.empty()){
            ans^=(i*temp.top());
        }
    }
    // printf("Case #%d: %llu\n",++cnt,ans);
    cout<<"Case #"<<++cnt<<": "<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        gen();
    return 0;
}