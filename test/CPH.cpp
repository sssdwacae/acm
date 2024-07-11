#include<bits/stdc++.h>
using namespace std;
int a[1005];
int f[1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=max(f[j]-f[i-1],ans);
		}
	}
	cout<<ans;
	return 0;
}