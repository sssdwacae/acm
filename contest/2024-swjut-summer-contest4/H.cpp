#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define int long long
#define mp make_pair

struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

struct rectangle
{
    int x1, y1, x2, y2, num;
    rectangle() {}
    rectangle(int _x1, int _y1, int _x2, int _y2, int _num)
    {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        num = _num;
    }
};

vector<Point> p;
vector<rectangle> r;
int ans = 0;

void solve()
{
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        int x, y;
        cin >> x >> y;
        p.push_back(Point(x, y));
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i].x1 <= x && r[i].y1 <= y && r[i].x2 >= x && r[i].y2 >= y)
            {
                r[i].num++;
                ans++;
            }
        }
    }
    else
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2)
        {
            p.push_back(Point(x1, y1));
            int x=x1,y=y1;
            for (int i = 0; i < r.size(); i++)
            {
                if (r[i].x1 <= x && r[i].y1 <= y && r[i].x2 >= x && r[i].y2 >= y)
                {
                    r[i].num++;
                    ans++;
                }
            }
        }
        else{
            r.push_back(rectangle(x1, y1, x2, y2, 0));
            for(int i=0;i<p.size();i++){
                if (r[r.size()-1].x1 <= p[i].x && r[r.size()-1].y1 <= p[i].y && r[r.size()-1].x2 >= p[i].x && r[r.size()-1].y2 >= p[i].y)
                {
                    r[r.size()-1].num++;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}