#include <bits/stdc++.h>
using namespace std;
vector<int> p;
bool vis[1005];
int dp[205][55][1005];
int main()
{
    p.push_back(-1);
    for (int i = 2; i <= 1000; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
            for (int j = i; j <= 1000; j += i)
                vis[j] = 1;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    dp[0][0][0] = 1;
    for (int i = 1; i < p.size(); i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (j && k >= p[i])
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k - p[i]];
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }
    printf("%d\n", dp[p.size() - 1][m][n]);
    return 0;
}