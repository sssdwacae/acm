#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#define fi first
#define se second
//#include<stdlib.h>
//#include <time.h>
//srand((unsigned)time(NULL));
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
using namespace std;
const double eps = 1e-7;
const int N = 510;
int n;
ll t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dcmp(ll x) {
    if (x == 0) return 0;
    return x > 0 ? 1 : -1;
}
struct Point{
    ll x, y;
    int id1, id2;
    Point() {id1 = id2 = -1; }
    Point (ll _x, ll _y) {
        x = _x; y = _y;
        id1 = id2 = -1;
    }
    void input() {
        scanf("%lld%lld", &x, &y);
    }
    bool operator==(const Point& b) const {
        return (x - b.x) == 0 && (y - b.y) == 0;
    }
    bool operator<(const Point& b) const {
        return dcmp(x - b.x) == 0 ? dcmp(y - b.y) < 0 : x < b.x;
    }
    Point operator-(const Point& b) const {
        return Point(x - b.x, y - b.y);
    }
    Point operator+(const Point& b) const {
        return Point(x + b.x, y + b.y);
    }
    ll operator*(const Point& b) const {
        return x * b.x + y * b.y;
    }
    ll operator^(const Point& b) const {
        return x * b.y - y * b.x;
    }
    ll dis2(Point p) {
        return (*this - p) * (*this - p);
    }
};
struct Line{
    Point s, e;
    int id;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
    }
    int segcrossseg(Line v) {
        int d1 = dcmp((e - s) ^ (v.s - s));
        int d2 = dcmp((e - s) ^ (v.e - s));
        int d3 = dcmp((v.e - v.s) ^ (s - v.s));
        int d4 = dcmp((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && dcmp((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && dcmp((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && dcmp((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && dcmp((e - v.s) * (e - v.e)) <= 0);
    }
    Point crossPoint(Line v) {
        ll a1 = (v.e - v.s) ^ (s - v.s);
        ll a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
}li[N];
vector<Point> g[N];
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("ansout.txt","w",stdout);
    scanf("%d%lld", &n, &t);
//    vector<Point> all;
    set<Point> p1, p2; //p1是所有的端点,p2是所有的交点
    for (int i = 1; i <= n; i++) {
        li[i].id = i;
        li[i].s.input();
        li[i].e.input();
        li[i].s.id1 = i; li[i].s.id2 = i;
        li[i].e.id1 = i; li[i].e.id2 = i;
        g[i].push_back(li[i].s);
        g[i].push_back(li[i].e);
//        all.push_back(li[i].s);
//        all.push_back(li[i].e);
        p1.insert(li[i].s);
        p1.insert(li[i].e);
    }
    Point st = li[1].s;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int ok = li[i].segcrossseg(li[j]);
            if (ok == 2) {
                Point tp = li[i].crossPoint(li[j]);
                tp.id1 = li[i].id; tp.id2 = li[j].id;
                p2.insert(tp);
                g[li[i].id].push_back(tp);
                g[li[j].id].push_back(tp);
//                all.push_back(tp);
            }
        }
    }
//    for (Point now : p2) {
//        printf("%lld %lld -%d -%d\n", now.x, now.y, now.id1, now.id2);
//    }
    int dir; //当前的方向
    Point tp = li[1].e - li[1].s;
    tp.x = dcmp(tp.x);
    tp.y = dcmp(tp.y);
    for (int i = 0; i < 4; i++) {
        if (dx[i] == tp.x && dy[i] == tp.y) {
            dir = i;
            break;
        }
    }
//    printf("%d\n", dir);
    vector<Point> road;
    road.push_back(st);
    Point now = st;
//    cout << now.id1 << " " << now.id2 << "\n";
    int f1 = 0;
    while (true) {
        int cc = 1;
        int a[2] = {0}; a[0] = now.id1;
        if (now.id2 != now.id1) {
            cc++; a[1] = now.id2;
        }
        bool f = false;
        Point best;
        for (int k = 0; k < cc; k++) {
            int id = a[k];
            for (int i = 0; i < (int)g[id].size(); i++) {
                Point nx = g[id][i];
                if (nx == now) continue;
                Point lv = nx - now;
                Point lv_dir = Point(dx[dir], dy[dir]);
                int status = lv * lv_dir;
                if (status > 0) {
                    if (f) {
                        if (now.dis2(nx) < now.dis2(best)) {
                            best = nx;
                        }
                    }
                    else {
                        f = true;
                        best = nx;
                    }
                }
            }
        }
        if (p1.find(best) != p1.end())
            dir = (dir + 2) % 4;
        else
            dir = (dir + 1) % 4;
        road.push_back(best);
        now = best;
        if (best == st) break;
    }
//    for (int i = 0; i < (int)road.size(); i++) {
//        printf("%lld %lld\n", road[i].x, road[i].y);
//    }
    ll len = 0;
    for (int i = 1; i < (int)road.size(); i++) {
        Point r1 = road[i], r2 = road[i - 1];
        ll tmp = abs(r1.x - r2.x) + abs(r1.y - r2.y);
        len += tmp;
    }
//    printf("%lld\n", len);
    ll last = t % len;
    if (last == 0) {
        printf("%d %d\n", st.x, st.y);
    }
    else {
        for (int i = 1; i < (int)road.size(); i++) {
            Point r1 = road[i - 1], r2 = road[i];
            ll tmp = abs(r1.x - r2.x) + abs(r1.y - r2.y);
            if (last > tmp) {
                last -= tmp;
            }
            else {
                Point lv = r2 - r1;
                int dd = 0;
                for (int j = 0; j < 4; j++) {
                    Point lv_dir = Point(dx[j], dy[j]);
                    if (lv * lv_dir > 0) {
                        dd = j;
                        break;
                    }
                }
                ll add_x = dx[dd] * last;
                ll add_y = dy[dd] * last;
                printf("%lld %lld\n", r1.x + add_x, r1.y + add_y);
                break;
            }
        }
    }
    return 0;
}
