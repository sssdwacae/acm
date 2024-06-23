#include<bits/stdc++.h>
using namespace std;
string s[25];
map<string,int> mp;
int cmp(pair<string,int> a,pair<string,int> b){
	return a.second>b.second;
}
int main(){
	// ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	string ans;
	for(int i=1;i<=n;i++){
		for(int j=0;j<32;j++){
			ans+=s[i][j];
			if(j%2==1){
				mp[ans]++;
            cout<<ans<<endl;
				ans.clear();
			}
         // cout<<ans<<endl;
		}
	}
	vector<pair<string,int>> v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<16;i++){
		cout<<v[i].first;
	}
	return 0;
}