#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

char DtoH(int temp)
{
    if(temp<=9)
        return temp+'0';
    else
        return temp-10+'A';
}
void solve()
{
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    vector<pair<int,int> >a;
    vector<vector<int> > b(n);
    for(int i=0;i<=255;i++)
        a.push_back(mp(i,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<s[i].size();j+=2){
            int temp=0;
            if(s[i][j+1]>='0'&&s[i][j+1]<='9')
                temp+=s[i][j+1]-'0';
            else
                temp+=s[i][j+1]-'A'+10;
            if(s[i][j]>='0'&&s[i][j]<='9')
                temp+=(s[i][j]-'0')*16;
            else
                temp+=(s[i][j]-'A'+10)*16;
            b[i].push_back(temp);
            a[temp].second++;
        }
    sort(a.begin(),a.end(),cmp);
    map<int,string> ans;
    for(int i=0;i<=15;i++){
        int temp=a[i].first;
        char c1,c2;
        int temp2=temp%16;
        temp/=16;
        c1=DtoH(temp);
        c2=DtoH(temp2);
        cout<<c1<<c2;
        string st;st=st+c1;st=st+c2;
        //ans[i]=st;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++){
            int pos=0,mn=300;
            for(int k=0;k<=15;k++)
                if(mn>fabs(a[k].first-b[i][j])){
                    mn=fabs(a[k].first-b[i][j]);
                    pos=k;
                }
            if(pos<=9)
                cout<<pos;
            else
                cout<<(char)('A'+pos-10);
        }
        cout<<endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--)
        solve();     
    return 0;
}