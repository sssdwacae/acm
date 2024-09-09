#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

struct node{
	int l,r,pos,b;
	node(){}
	node(int _l,int _r,int _pos,int _b){
		l=_l;
		r=_r;
		pos=_pos;
		b=_b;
	}
};

bool cmp1(node t1,node t2)
{
	if(t1.l==t2.l)
		return t1.b<t2.b;
	else
		return t1.l<t1.l;
}

bool cmp2(node t1,node t2)
{
	return t1.pos<t2.pos;
}

void solve()
{
	int n;
	cin>>n;
	vector<node> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		a[i].pos=i;
	}
	sort(a.begin()+1,a.end(),cmp1);
	int enda=n;//当前不能跨过的最近区间
	int endr=n;//当前插入的最后坐标
	for(int i=n;i>=1;i--){
		int R=i;
	}
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
