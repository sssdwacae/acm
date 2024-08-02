#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct node{
	int s,t;		
};
node a[100005];
int t,m;
int cnt=0;
int n;
map<int,int>mp;
queue<node>q;
int main(){
	IOS;
	cin>>n;
	while(n--){
		cin>>t>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].s;
			a[i].t=t;
			q.push(a[i]);
		}
		while(!q.empty()){
			if(mp[q.front().s]==0){
				cnt++;
				mp[q.front().s]++;
			}
			if(t>86400||q.back().t-q.front().t>86400){
				while(q.back().t-q.front().t>86400){
					mp[q.front().s]--;
					if(mp[q.front().s]==0){
						cnt--;
					}
					q.pop();
				}
				continue;
			}
			q.pop();
		}
		cout<<cnt<<'\n';
	}
	return 0;
}