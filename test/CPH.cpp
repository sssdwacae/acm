#include<bits/stdc++.h>
using namespace std;
string s[25];
map<string,int>mp;
int cmp(pair<string,int> a,pair<string,int> b){
	return a.second>b.second||(a.second==b.second&&a.first<b.first);
}
int fun(string x){
	int cnt=0;
	int ans=0;
	for(int i=x.length()-1;i>=0;i--){
		if(x[i]>='0'&&x[i]<='9'){
			ans+=(x[i]-'0')*pow(16,cnt);
			cnt++;
		}
		if(x[i]>='A'&&x[i]<='F'){
			ans+=(x[i]-'A'+10)*pow(16,cnt);
			cnt++;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	string ans;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].length();j++){
			ans+=s[i][j];
			if(j%2==1){
				mp[ans]++;
				ans.clear();
			}
		}
	}
	vector<pair<string,int>>v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<16;i++){
		cout<<v[i].first;
	}
	cout<<'\n';
	bool flag=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].length();j++){
			ans+=s[i][j];
			if(j%2==1){
				flag=0;
				int minn=0;
				int m=0x3f3f3f3f;
				for(int k=0;k<16;k++){
					
						if(abs(fun(v[k].first)-fun(ans))<m){
							m=abs(fun(v[k].first)-fun(ans));
							minn=k;
						}
					
				}
				if(flag==1){
					ans.clear();
					continue;
				}
				if(minn>=0&&minn<=9){
					cout<<minn;
				}
				else{
					cout<<(char)('A'+minn-10);
				}
				ans.clear();
			}
		}
		cout<<'\n';
	}
	return 0;
}