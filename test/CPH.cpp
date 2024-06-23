#include<bits/stdc++.h>
using namespace std;
string fun(string x){
	string cnt;
	int ans=0;
	int c=0;
	for(int i=x.length()-1;i>=0;i--){
		if(x[i]>='0'&&x[i]<='9'){
			ans+=(x[i]-'0')*pow(16,c);
		}
		if(x[i]>='A'&&x[i]<='F'){
			ans+=(x[i]-'A'+10)*pow(16,c);
		}
		c++;
	}
	string h;
	while(ans!=0){
		h.insert(h.begin(),(ans%2)+'0');
		ans/=2;
	}
	reverse(h.begin(),h.end());
	if(h.length()!=12){
		while(h.length()!=12){
			h.insert(h.begin(),'0');
		}
	}
	return h;
}
int sf(string y){
	int c=0;
	string k;
	int cnt=0;
	for(int i=y.length()-1;i>=0;i--){
		if(i%3==0){
			for(int j=k.length()-1;j>=0;j--){
				c+=(k[i]-'0')*pow(2,cnt);
				cnt++;
			}
		}
		k+=y[i];
	}
	return c;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(s.length()%3==1){
			s.insert(s.begin(),'0');
			s.insert(s.begin(),'0');
		}
		else if(s.length()%3==2){
			s.insert(s.begin(),'0');
		}
		string ans;
		int sum=0;
		for(int i=sum;i<s.length();i++){
			if(i%3==2){
				ans=fun(ans);
				cout<<sf(ans);
				sum=i+1;
				ans.clear();
			}
			else{
				ans+=s[i];
			}
		}
	}
	return 0;
}