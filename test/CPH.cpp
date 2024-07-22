#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int ans;
int k[105][105];
const int MOD=1e6+7;
int dfs(int x,int i)//0 1
{	
	// cout<<x<<' '<<i<<endl;
	if(x==m)
		return 1;
	if(i>n)
		return 0;
	if(x>m)
		return 0;
	if(k[x][i])
		return k[x][i];
	int temp=0;
	
	for(int j=0;j<=a[i];j++)
		temp=(temp+dfs(x+j,i+1))%MOD;

	k[x][i]=temp;
	return k[x][i];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	// cout<<"su\n";
	cout<<dfs(0,1)%MOD;
	// cout<<ans%MOD;
	return 0;
}