#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define endl '\n'

int t;

double x, y, r, vx, vy, lx, ly, rx, ry;
double x1, x2, Y1, y2, midx, midy, k;

void solve()
{
    cin >> x >> y >> r >> vx >> vy >> lx >> ly >> rx >> ry;

    if (ry - ly < 2 * r || rx - lx < 2 * r)
    {
        cout << "No\n";
        return;
    }

    if (vx == 0)
    {
        x1 = x2 = x;
        // Y1 = ly, y2 = ry;
        if ((ly - y) * vy <= 0)
            Y1 = y;
        else
            Y1 = ly;
        if ((ry - y) * vy <= 0)
            y2 = y;
        else
            y2 = ry;
    }
    else if (vy == 0)
    {
        Y1 = y2 = y;
        // x1 = lx, x2 = rx;
        if ((lx - x) * vx <= 0)
            x1 = x;
        else
            x1 = lx;
        if ((rx - x) * vx <= 0)
            x2 = x;
        else
            x2 = rx;
    }
    else
    {
        if ((lx - x) * vx <= 0)
            x1 = x;
        else
            x1 = lx;
        if ((rx - x) * vx <= 0)
            x2 = x;
        else
            x2 = rx;

        Y1 = (double)(x1 - x) * vy / vx + y;
        y2 = (double)(x2 - x) * vy / vx + y;
    }

    // cout << x1 << ' ' << Y1 << ' ' << x2 << ' ' << y2 << '\n';

    if (x1 > x2)
        swap(x1, x2);
    if (Y1 > y2)
        swap(Y1, y2);
    if (x1 + r <= rx && x2 - r >= lx && Y1 + r <= ry && y2 - r >= ly)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

