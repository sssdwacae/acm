#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countGoodIntervals(const vector<int>& a, int n, int k) {
    unordered_map<int, int> countMap;
    int left = 0, right = 0;
    int goodCount = 0;
    int numElementsMeetingK = 0;
    
    while (right < n) {
        countMap[a[right]]++;
        if (countMap[a[right]] == k) {
            numElementsMeetingK++;
        }
        if (countMap[a[right]] == k + 1) {
            numElementsMeetingK--;
        }
        
        while (numElementsMeetingK == countMap.size()) {
            goodCount += n - right;
            countMap[a[left]]--;
            if (countMap[a[left]] == k - 1) {
                numElementsMeetingK--;
            }
            if (countMap[a[left]] == k) {
                numElementsMeetingK++;
            }
            left++;
        }
        right++;
    }
    
    return goodCount;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << countGoodIntervals(a, n, k) << endl;
    }
    return 0;
}
