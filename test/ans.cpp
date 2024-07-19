#include <bits/stdc++.h>
#define PI atan(1.0)*4
#define rp(i,s,t) for (register int i = (s); i <= (t); i++)
#define RP(i,t,s) for (register int i = (t); i >= (s); i--)
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define m_p make_pair
#define p_b push_back
#define ins insert
#define era erase
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3f
#define dg if(debug)
#define pY puts("YES")
#define pN puts("NO")
#define outval(a) cout << "Debuging...|" << #a << ": " << a << "\n";
#define outval2(a,b) cout << "Debuging...|" << #a << ": " << a <<"\t"<< #b << ": " << b << "\n";
#define outval3(a,b,c) cout << "Debuging...|" << #a << ": " << a <<"\t"<< #b << ": " << b <<"\t"<< #c << ": " << c << "\n";
using namespace std;
int debug = 0;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
const int N = 1e5+7;
double calc(int x1,int y1,int x2,int y2){
    double ans=x1*y1+x2*y2;
    if(y1>y2) ans+=(y1-y2)*x2*1.0/2;
    else ans+=(y2-y1)*x1*1.0/2;
    return ans;
}
int kcase=0;
void solve(){
    int w1=read(),h1=read();
    int w2=read(),h2=read();
    double ans1=min(calc(w1,h1,w2,h2),calc(w1,h1,h2,w2));
    double ans2=min(calc(h1,w1,w2,h2),calc(h1,w1,h2,w2));
    printf("Case %d: %.6f\n",++kcase,min(ans1,ans2));
}
int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    //debug = 1;
#endif
    //time_t beg, end;
    //if(debug) beg = clock();

    int T=read();
    while(T--) solve();

    /*
    if(debug) {
        end = clock();
        printf("time:%.2fs\n", 1.0 * (end - beg) / CLOCKS_PER_SEC);
    }
    */
    return 0;
}