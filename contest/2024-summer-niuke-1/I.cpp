#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair

const int M = 1e3 + 5;
int cnt[M][M][6];
// i j  方向  1上 2下 3左 4右
int n, m;
string s[M];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void huan(int x, int y, int d, int pos)
{
    // cnt[]
    if (cnt[x][y][d] > 0) // 已经完成这个环的赋值
    {                     // 成环退出
        return;
    }
    switch (s[x][y])
    {
    case '/':
        switch (d)
        {
        case 1:
            cnt[x][y][2] = pos;
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], 4, pos);
            break;
        case 2:
            cnt[x][y][1] = pos;
            cnt[x][y][3] = pos;
            huan(x + dx[d], y + dy[d], 3, pos);
            break;
        case 3:
            cnt[x][y][2] = pos;
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], 1, pos);
            break;
        case 4:
            cnt[x][y][1] = pos;
            cnt[x][y][3] = pos;
            huan(x + dx[d], y + dy[d], 2, pos);
            break;
        }
        break;
    case '-':
        switch (d)
        {
        case 1:
            cnt[x][y][2] = pos;
            huan(x + dx[d], y + dy[d], 2, pos);
            break;
        case 2:
            cnt[x][y][1] = pos;
            huan(x + dx[d], y + dy[d], 1, pos);
            break;
        case 3:
        case 4:
            cnt[x][y][3] = pos;
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], d, pos);
            break;
        }
        break;
    case '\\':
        switch (d)
        {
        case 1:
            cnt[x][y][2] = pos;
            cnt[x][y][3] = pos;
            huan(x + dx[d], y + dy[d], 3, pos);
            break;
        case 2:
            cnt[x][y][1] = pos;
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], 4, pos);
            break;
        case 3:
            cnt[x][y][1] = pos;
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], 2, pos);
            break;
        case 4:
            cnt[x][y][2] = pos;
            cnt[x][y][3] = pos;
            huan(x + dx[d], y + dy[d], 1, pos);
            break;
        }
        break;
    case '|':
        switch (d)
        {
        case 1:
        case 2:
            cnt[x][y][1] = pos;
            cnt[x][y][2] = pos;
            huan(x + dx[d], y + dy[d], d, pos);
            break;
        case 3:
            cnt[x][y][4] = pos;
            huan(x + dx[d], y + dy[d], 4, pos);
            break;
        case 4:
            cnt[x][y][3] = pos;
            huan(x + dx[d], y + dy[d], 3, pos);
            break;
        }
        break;
    }
}

void dfs(int x, int y, int d, int pos, int sx, int sy, int sd)
{
    if (cnt[x][y][d] == 0)
    { // 成环退出
        huan(x, y, d, pos);
        return;
    }
    else if (x < 1 || x > n || y < 1 || y > m)
    { // 射线退出
        return;
    }
    cnt[x][y][d] = 0; // 标记这个点走过
    switch (s[x][y])
    {
    case '/':
        switch (d)
        {
        case 1:
            dfs(x + dx[d], y + dy[d], 4, pos + 1, sx, sy, sd);
            break;
        case 2:
            dfs(x + dx[d], y + dy[d], 3, pos + 1, sx, sy, sd);
            break;
        case 3:
            dfs(x + dx[d], y + dy[d], 1, pos + 1, sx, sy, sd);
            break;
        case 4:
            dfs(x + dx[d], y + dy[d], 2, pos + 1, sx, sy, sd);
            break;
        }
        break;
    case '-':
        switch (d)
        {
        case 1:
            dfs(x + dx[d], y + dy[d], 2, pos + 1, sx, sy, sd);
            break;
        case 2:
            dfs(x + dx[d], y + dy[d], 1, pos + 1, sx, sy, sd);
            break;
        case 3:
            dfs(x + dx[d], y + dy[d], d, pos, sx, sy, sd);
            break;
        case 4:
            dfs(x + dx[d], y + dy[d], d, pos, sx, sy, sd);
            break;
        }
        break;
    case '\\':
        switch (d)
        {
        case 1:
            dfs(x + dx[d], y + dy[d], 3, pos + 1, sx, sy, sd);
            break;
        case 2:
            dfs(x + dx[d], y + dy[d], 4, pos + 1, sx, sy, sd);
            break;
        case 3:
            dfs(x + dx[d], y + dy[d], 2, pos + 1, sx, sy, sd);
            break;
        case 4:
            dfs(x + dx[d], y + dy[d], 1, pos + 1, sx, sy, sd);
            break;
        }
        break;
    case '|':
        switch (d)
        {
        case 1:
            dfs(x + dx[d], y + dy[d], d, pos, sx, sy, sd);
            break;
        case 2:
            dfs(x + dx[d], y + dy[d], d, pos, sx, sy, sd);
            break;
        case 3:
            dfs(x + dx[d], y + dy[d], 4, pos + 1, sx, sy, sd);
            break;
        case 4:
            dfs(x + dx[d], y + dy[d], 3, pos + 1, sx, sy, sd);
            break;
        }
        break;
    }
}

void solve()
{
    memset(cnt, -1, sizeof(cnt));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    int T = 1;
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        string c;
        cin >> c;
        int d = 0;
        if (c == "below")
            d = 2;
        else if (c == "right")
            d = 4;
        else if (c == "left")
            d = 3;
        else if (c == "above")
            d = 1;
        if (cnt[x][y][d] != -1)
            cout << cnt[x][y][d] << endl;
        else
        {
            cout << d << "enter\n";
            dfs(x + dx[d], y + dy[d], d, 0, x + dx[d], y + dy[d], d);
            cout << cnt[x][y][d] << endl;
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    // cin>>T;
    T = 1;
    while (T--)
        solve();
    return 0;
}