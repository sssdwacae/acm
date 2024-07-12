#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		for(int i=1;i<=t;i++){
			v.push_back(i);
		}
		bool flag=1;
		while(v.size()>3){
			vector<int> temp;
			flag=!flag;
			if(flag==0){
				for(int i=0;i<v.size();i++){
					if(i%2==1){
						
					}
					else{
						temp.push_back(v[i]);
					}
				}
			}
			else{
				for(int i=0;i<v.size();i++){
					if(i%3==2){
						
					}
					else{
						temp.push_back(v[i]);
					}
				}
			}
			v.clear();
			for(int i=0;i<temp.size();i++){
				v.push_back(temp[i]);
			}
			temp.clear();
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}