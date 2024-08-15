#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    map<string,string> mp;
    string t1,t2;
    for(int i=0;i<n;i++)
    {
        cin>>t1>>t2;
        t2.erase(t2.end()-1);
        // cout<<t2<<endl;
        mp[t2]=t1;
    }

    // cout<<"\nquery\n";

    while(q--)
    {
        string str;
        cin>>str;
        string na="";
        int x=0;
        while(x<str.length() && str[x]!='.')
            na+=str[x++];
        
        string t=mp[na];
        int l=0, r=t.length()-1;

        while(x<str.length())
        {
            if(str[x]=='f')
            {
                l+=5;
                // while(t[r]!=',')
                //     r--;
                // r--;
                int cnt=0;
                while(1)
                {
                    r--;
                    if(t[r]=='<')
                        cnt++;
                    if(t[r]=='>')
                        cnt--;
                    if(cnt==0 && t[r]==',')
                        break;
                }
                r--;
                cerr<<"first: "<<l<<' '<<r<<endl;
            }
            if(str[x]=='e')
            {
                int cnt=0;
                l+=5;
                while(1)
                {
                    l++;
                    if(t[l]=='<')
                        cnt++;
                    if(t[l]=='>')
                        cnt--;
                    if(cnt==0 && t[l]==',')
                        break;
                }
                l++;
                r--;
                cerr<<"second: "<<l<<' '<<r<<endl;
            }
            x++;
        }

        cerr<<str<<endl;
        cerr<<t<<endl;
        cerr<<l<<' '<<r<<endl;
        cerr<<endl;
        for(int i=l;i<=r;i++)
            cout<<t[i];
        cout<<endl;
        // cout<<endl;
    }
}
/*
1 2
pair<pair<pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>,pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>>,pair<pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>,pair<pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>,pair<pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>,pair<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>,pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>>>>>>> b;
b.first.first.fisrt
b.second.second.second

*/