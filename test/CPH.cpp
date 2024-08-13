#include<bits/stdc++.h>
using namespace std;
int b[1005];
int n;
void v(int *a,int l,int r,int mid){
	mid=(l+r)/2;
	for(int i=l;i<=mid;i++){
		b[i]=a[i];
	}
	if(mid!==l){
		v(b,l,mid,0);
	}
	else{
		for(int i=1;i<=n;i++){
			if(i%(mid-l+1)==0){
				if(b[i+1]<b[i]){
					swap(b[i],b[i+1]);
				}
			}
		}
		return;
	}
}
int main(){
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v(a,1,n,0);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}