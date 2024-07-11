#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<string,string>mp;
	string k;
	string b;
	while(n--){
		cin>>k>>b;
		mp[k]=b;
	}
	string ans;
	string h;
	cin>>h;
	int sum=0;
	for(int i=0;i<h.length();i++){
		if(i==h.length()-1){
			for(int j=sum;j<=i;j++){
				ans+=h[j];
			}
			if(ans.length()>0){
				if(mp.find(ans)==mp.end()){
					cout<<"UNK";
				}
				else{
					cout<<mp[ans];
				}
			}
		}
		else if(!(h[i]<='z'&&h[i]>='a')){
			for(int j=sum;j<i;j++){
				ans+=h[j];
			}
			if(ans.length()>0){
				if(mp.find(ans)==mp.end()){
					cout<<"UNK";
				}
				else{
					cout<<mp[ans];
				}
			}
			cout<<h[i];
			ans.clear();
			sum=i+1;
		}
		
	}
	return 0;
}