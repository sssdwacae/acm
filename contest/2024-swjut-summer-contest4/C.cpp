#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define ll long long
#define mp make_pair


void solve()
{
    int n,q;
    cin>>n>>q; //识别n次，有q个问题 3 4
    int c;
    cin>>c; //5
    map<string,string> m;
    string ss="";
    for(int i=1;i<=q+1;i++)
        ss+='0';
    for(int i=0;i<c;i++){
        string s;
        cin>>s;
        m[s]=ss;
    }
    for(int i=1;i<=q;i++){
        int M;
        cin>>M;
        for(int j=1;j<=M;j++){
            string s;
            cin>>s;
            m[s][i]='1';
        }
    }
    vector<pair<string,string> > v(m.begin(),m.end());
    // vector<pair<string,string> > ans;
    // for(int i=0;i<v.size();i++){

    // }
    for(int i=1;i<=n;i++){//每n次询问
    //     vector<pair<string,vector<int> > >temp;
    //     vector<pair<string,vector<int> > > tt=v;
        string s0="0";
        for(int j=1;j<=q;j++){
            char c;
            cin>>c;
            s0=s0+c;
        }
        vector<string> ans;
        for(int j=0;j<v.size();j++)
            if(v[j].second==s0)
                ans.push_back(v[j].first);
        if(ans.size()==1)
            cout<<ans[0]<<endl;
        else
            cout<<"Let's go to the library!!\n";
    //     for(int j=1;j<=q;j++){//对于每q个问题
    //         int choice;
    //         cin>>choice;
    //         for(int k=0;k<tt.size();k++)
    //             if(tt[k].second[j]==choice)
    //                 temp.push_back(tt[k]);
    //         tt=temp;
    //         temp.clear();
    //     }
    //     if(tt.size()==1){
    //         cout<<tt[0].first<<endl;
    //     }
    //     else{
    //         cout<<"Let's go to the library!!\n";
    //     }
    }
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