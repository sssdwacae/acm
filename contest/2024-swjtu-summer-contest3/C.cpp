#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair

int xw, yw, Xw, Yw, xb, yb, Xb, Yb;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x)
{
    // 平行
    if (fabs(x) < eps)
        return 0;
    // 相交方向
    if (x < 0)
        return -1;
    else
        return 1;
}
// 点的定义
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    // 减法重载
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    // 叉乘
    double operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    // 点乘
    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }
};
// 直线定义
struct Line
{
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }
    pair<int, Point> operator&(const Line &b) const
    {
        Point res = s;
        if (sgn((s - e) ^ (b.s - b.e)) == 0)
        {
            if (sgn((s - b.e) ^ (b.s - b.e)) == 0)
                return make_pair(0, res); // 重合
            else
                return make_pair(1, res); // 平行
        }
        double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return make_pair(2, res);
    }
};
// 判断线段l1和l2是否相交
bool inter(Line l1, Line l2)
{
    return
        // 快速排斥实验
        max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
        max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
        max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
        max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
        // 跨立实验
        sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
        sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

//*判断点在线段上
bool OnSeg(Point P, Line L)
{
    return sgn((L.s - P) ^ (L.e - P)) == 0 &&
           sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
           sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

//*两点间距离
double dist(Point a, Point b)
{
    return sqrt((a - b) * (a - b));
}

// 点到线段的距离
// 返回点到线段最近的点
Point NearestPointToLineSeg(Point P, Line L)
{
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    if (t >= 0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x) * t;
        result.y = L.s.y + (L.e.y - L.s.y) * t;
    }
    else
    {
        if (dist(P, L.s) < dist(P, L.e))
            result = L.s;
        else
            result = L.e;
    }
    return result;
}

Point PointToLine(Point P, Line L)
{
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
    return result;
}

void solve()
{
    cin >> xw >> yw >> Xw >> Yw >> xb >> yb >> Xb >> Yb;
    Point a1(xw, yw), a2(Xw, Yw);
    Point b1(xb, yb), b2(Xb, Yb);
    // Line l1(a1, a2), l2(b1, b2);

    pair<int, Point> c2 = Line(a1, a2) & Line(b1, b2);
    if (c2.first == 2)
    { // 直线相交
        // cout<<OnSeg(c.second,l1)<<' '<<OnSeg(c.second,l2)<<'?'<<endl;
        if ((OnSeg(c2.second, Line(a1, a1)) || OnSeg(c2.second, Line(a2, a2))) && (OnSeg(c2.second, Line(b2, b2)) || OnSeg(c2.second, Line(b1, b1))))
        // 直线交点在两个线段端点
        {
            cout << "inf\n";
            return;
        }
        else if (OnSeg(c2.second, Line(a1, a2)) && OnSeg(c2.second, Line(b1, b2)) && ((OnSeg(c2.second, Line(a1, a1)) || OnSeg(c2.second, Line(a2, a2))))) // b在a上
        {
            cout << "0.000\n";
            return;
        }
        else if (OnSeg(c2.second, Line(a1, a2)) && OnSeg(c2.second, Line(b1, b2)) && (OnSeg(c2.second, Line(b2, b2)) || OnSeg(c2.second, Line(b1, b1)))) // a在b上
        {
            cout << "inf\n";
            return;
        }
        else
        {
            cout << "0.000\n";
            return;
        }
    }

    if (yw > Yw)
    {
        Point temp = a1;
        a1 = a2;
        a2 = temp;
    }
    else if (yw == Yw)
    {
        if (xw > Xw)
        {
            Point temp = a1;
            a1 = a2;
            a2 = temp;
        }
    }
    if (yb > Yb)
    {
        Point temp = b1;
        b1 = b2;
        b2 = temp;
    }
    else if (yb == Yb)
    {
        if (xb > Xb)
        {
            Point temp = b1;
            b1 = b2;
            b2 = temp;
        }
    }
    
    Line l1(b2, a2), l2(b1, a1);
    pair<int, Point> c = l1 & l2;
    if (c.first == 1)
    { // 平行
        cout << "inf\n";
        return;
    }
    // 有交点
    Point ca = NearestPointToLineSeg(c.second, Line(a1, a2));
    Point cb = NearestPointToLineSeg(c.second, Line(b1, b2));

    if (dist(ca, c.second) > dist(cb, c.second))
    {
        cout << "inf\n";
        return;
    }
    else
    {
        double ans = 0.5 * dist(a1, a2) * dist(PointToLine(c.second, Line(a1, a2)), c.second);
        printf("%0.10f\n", ans);
        return;
        // cout<<endl<<dist(PointToLine(c.second,Line(a1,a2)),c.second)<<' '<<dist(a1, b1) <<endl;
    }
    return;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T;
    cin >> T;
    int cnt = 0;
    while (T--)
    {
        cout << "Case " << ++cnt << ": ";
        solve();
    }
    return 0;
}