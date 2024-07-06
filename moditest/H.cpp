#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N=1e5+5;
#define int long long
#define mp make_pair

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> count(n,0);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_set<int> check;
    
    for (int i = 0; i <= n; i++) {
        min_heap.push(i);
    }
    
    int Top = 0;
    for (int i = 0; i < m; ++i) {
        count[a[i]]++;
        if (count[a[i]] == 1) {
            check.insert(a[i]);
            while (!min_heap.empty() && check.find(min_heap.top()) != check.end()) {
                min_heap.pop();
            }
        }
    }
    Top = min_heap.top();
    
    int ans = Top;
    for (int i = m; i < n; ++i) {
        int outgoing = a[i - m];
        int incoming = a[i];
        
        count[outgoing]--;
        if (count[outgoing] == 0) {
            check.erase(outgoing);
            min_heap.push(outgoing);
        }
        
        count[incoming]++;
        if (count[incoming] == 1) {
            check.insert(incoming);
            while (!min_heap.empty() && check.find(min_heap.top()) != check.end()) {
                min_heap.pop();
            }
        }
        
        Top = min_heap.top();
        ans = min(ans, Top);
    }
    
    cout<<ans;
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