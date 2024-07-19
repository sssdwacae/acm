#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(2 * n, vector<int>(2 * n, 0));

    // 动态规划的初始化和计算
    for (int len = 1; len < 2 * n; len++) { // 子数组的长度
        for (int i = 0; i + len < 2 * n; i++) {
            int j = i + len;
            // 如果子数组的首尾元素相同
            if (a[i] == a[j]) {
                int score = (j - i + 1) * a[i];
                if (len > 1) {
                    score += dp[i + 1][j - 1];
                }
                dp[i][j] = max(dp[i][j], score);
            }
            // 尝试所有可能的分割方式
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[0][2 * n - 1] << endl;
    return 0;
}
