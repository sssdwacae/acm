#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair
#define L a[i].l
#define R a[i].r
#define H a[i].h

struct node
{
    int l,r,h;
    node(){}
    node(int _l,int _r,int _h){
        l=_l;r=_r;h=_h;
    }
};

struct plat
{
    int l,r;
    plat(){}
    plat(int _l,int _r){
        l=_l;r=_r;
    }
};


bool cmp(node temp1,node temp2)
{
    if(temp1.h==temp2.h)
        return temp1.l<temp2.l;
    else
        return temp1.h>temp2.h;
}

void solve()
{
    int n,x,y;
    cin>>n;
    vector<node> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r>>a[i].h;
    cin>>x>>y;
    sort(a.begin()+1,a.begin()+1+n,cmp);
    vector<plat> temp;
    for(int i=1;i<=n;i++){
        if(y<a[i].h)
            continue;
        if(i==1)
            temp.push_back(plat(L,R));
        else{
            if(H!=a[i-1].h)//高度改变
                temp.push_back(plat(L,R));
            else{
                if(L==a[i-1].r){
                    temp.pop_back();
                    temp.push_back(plat(a[i-1].l,R));
                }
                else
                    temp.push_back(plat(L,R));
            }
        }
    }
    for(int i=0;i<temp.size();i++){
        if(x>temp[i].l&&x<temp[i].r)
            x=temp[i].r;
    }
    cout<<x<<endl;
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