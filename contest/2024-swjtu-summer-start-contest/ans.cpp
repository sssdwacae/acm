#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n;
    cin>>n;
    map<string,string> mp;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    string s;
    cin>>s;
    string temp;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            temp=temp+s[i];
        }
        else{
            if(temp.size()&&mp.find(temp)==mp.end()){
                cout<<"UNK";
            }
            else{
                cout<<mp[temp];
            }
            temp.clear();
            cout<<s[i];
        }
        if(i==(int)s.size()-1&&temp.size()){
            if(mp.find(temp)==mp.end()){
                cout<<"UNK";
            }
            else{
                cout<<mp[temp];
            }
            temp.clear();
        }
    }
    
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("in.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}