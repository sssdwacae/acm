#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    string temp(m+2,'K');
    vector<string> a(n+2,temp);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]='K'+a[i]+'K';
    }
    if(n*m%3!=1){
        cout<<"No\n";
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i==1&&j==m){
                if(a[i][j]!='.'){
                    cout<<"No\n";
                    return;
                }
                else
                    continue;
            }
            switch (a[i][j]){
                case '.' :
                    cout<<"No\n";
                    return;
                    break;
                case 'L' :
                    if(a[i][j-1]!='C'){
                        cout<<"No\n";
                        return;
                    }
                    break;
                case 'R' :
                    if(a[i][j+1]!='C'){
                        cout<<"No\n";
                        return;
                    }
                    break;
                case 'U' :
                    if(a[i-1][j]!='C'){
                        cout<<"No\n";
                        return;
                    }
                    break;
                case 'D' :
                    if(a[i+1][j]!='C'){
                        cout<<"No\n";
                        return;
                    }
                    break;
                case 'C':
                    if( (a[i][j+1]=='L'&&a[i+1][j]=='U')||
                        (a[i][j+1]=='L'&&a[i-1][j]=='D')||
                        (a[i][j-1]=='R'&&a[i+1][j]=='U')||
                        (a[i][j-1]=='R'&&a[i-1][j]=='D')
                    ){
                        continue;
                    }
                    else{
                        cout<<"No\n";
                        return;
                    }
                    break;
            }
        }
    cout<<"Yes\n";
    return;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}