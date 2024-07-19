#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mpi make_pair

bool cmp(pair<string,int> a,pair<string,int> b)
{
    return a.second>b.second;
}
int cc=0;
void solve()
{
    cout<<"Case "<<++cc<<": ";
    map<string,int> mp1,mp2,mp3,mp,cnt;
    int n,m,k;
    cin>>n>>m>>k;
    int pos=0;
    vector<string> s;
    string temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(temp[temp.size()-1]==' '){
            // cout<<"?";
            temp.erase(temp.end());
        }
        if(mp3[temp])
            continue;
        if(pos>=m&&mp1[temp]!=k-1)
            continue;
        mp1[temp]++;
        if(mp1[temp]==k){
            mp1[temp]=0;
            mp2[temp]++;
            pos-=k-1;
        }
        if(mp2[temp]==k){
            mp2[temp]=0;
            mp3[temp]++;
            pos-=k-1;
        }
        s.push_back(temp);
        pos++;
    }
    pos=0;
    vector<pair<string,int> >ans;
    for(int i=0;i<s.size();i++){
        temp=s[i];
        cnt[temp]++;
        if(cnt[temp]<=mp[temp])
            continue;
        if(mp[temp]==k*k)
            continue;
        if(mp3[temp]){
            mp[temp]+=k*k;
            // cout<<temp<<3<<' ';
            ans.push_back(mpi(temp,3));
            mp3[temp]=0;
            pos++;
        }
        else if(mp2[temp]){
            mp[temp]+=k;
            ans.push_back(mpi(temp,2));
            // cout<<temp<<2<<' ';
            mp2[temp]--;
            pos++;
        }
        else if(mp1[temp]){
            mp[temp]+=1;
            // cout<<temp<<' ';
            ans.push_back(mpi(temp,1));
            pos++;
            mp1[temp]--;
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        if(i!=m-1){
            if(ans[i].second==1)
                cout<<ans[i].first<<' ';
            else
                cout<<ans[i].first<<ans[i].second<<' ';
        }
        else{
            if(ans[i].second==1)
                cout<<ans[i].first<<' ';
            else
                cout<<ans[i].first<<ans[i].second<<' ';
        }
    }
    for(int i=pos;i<m;i++){
        if(i==m-1)
            cout<<-1;
        else
            cout<<-1<<' ';
    }
    cout<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();     
    return 0;
}