#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to determine the winner
string game_winner(int n, const vector<int>& arr) {
    set<int> S(arr.begin(), arr.end());
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    // Construct the graph
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int g = gcd(arr[i], arr[j]);
            if (S.find(g) == S.end()) {
                graph[i][j] = graph[j][i] = 1;
            }
        }
    }
    
    // Minimum spanning tree (MST) using Prim's algorithm
    vector<bool> in_mst(n, false);
    vector<int> min_edge(n, INT_MAX);
    min_edge[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    
    int mst_weight = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (in_mst[u]) continue;
        in_mst[u] = true;
        mst_weight += weight;
        
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !in_mst[v] && graph[u][v] < min_edge[v]) {
                min_edge[v] = graph[u][v];
                pq.push({min_edge[v], v});
            }
        }
    }
    
    // If the size of the MST is odd, dXqwq wins; otherwise, Haitang wins
    return mst_weight % 2 == 0 ? "Haitang" : "dXqwq";
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("ansout.txt","w",stdout);
    int t;
    cin >> t;
    vector<string> results;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        results.push_back(game_winner(n, arr));
    }
    
    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}
