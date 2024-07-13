#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int nx, ny; // 当前坐标

struct Line
{
    int x1, y1, x2, y2;
    Line() {}
    Line(int _x1, int _y1, int _x2, int _y2)
    {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};

vector<Line> X; // x轴平行
vector<Line> Y;
int d; // U1D2L3R4

bool cmp1(Line a, Line b)
{
    if(a.y1!=b.y1)  
        return a.y1 < b.y1;
    else
        return a.x1 < b.x1;
}
bool cmp2(Line a, Line b)
{
    if(a.x1!=b.x1)
        return a.x1 < b.x1;
    else
        return a.y1 < b.y1;
}
void solve()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1, x1, y1, x2, y2; i <= n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (i == 1)
        {
            nx = x1;
            ny = y1;
            if (x1 == x2 && y1 < y2)
                d = 1;
            else if (x1 == x2 && y1 > y2)
                d = 2;
            else if (y1 == y2 && x1 < x2)
                d = 4;
            else
                d = 3;
        }
        if (x1 == x2)
        { // 竖直直线
            Y.push_back(Line(x1, min(y1, y2), x2, max(y1, y2)));
        }
        else if (y1 == y2)
        { // 水平直线
            X.push_back(Line(min(x1, x2), y1, max(x1, x2), y2));
        }
    }

    


    Line nowl;
    
    sort(X.begin(), X.end(), cmp1);
    sort(Y.begin(), Y.end(), cmp2);
    
    int T = 0;

    // vector<Line> temp;
    // for(int i=0;i<X.size();i++){
    //     int s=X[i].x1,e=X[i].x2;
    //     int j;
    //     for(j=i+1;j<X.size();j++){
    //         // cout<<e<<' '<<X[j].y1<<endl;
    //         if((e>=X[j].x1)&&X[i].y1==X[j].y1){
    //             e=max(e,X[j].x2);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     if(e==X[i].x2){
    //         temp.push_back(X[i]);
    //     }
    //     else{
    //         temp.push_back(Line(s,X[i].y1,e,X[i].y2));
    //         i=j;
    //     }
    // }   
    // // cout<<temp.size()<<endl;
    // X=temp;
    // temp.clear();

    // for(int i=0;i<Y.size();i++){
    //     int s=Y[i].y1,e=Y[i].y2;
    //     int j;
    //     for(j=i+1;j<Y.size();j++){
    //         // cout<<e<<' '<<X[j].y1<<endl;
    //         if(e>=Y[j].y1&&Y[i].x1==Y[j].x1){
    //             e=max(e,Y[j].y2);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     if(e==Y[i].y2){
    //         temp.push_back(Y[i]);
    //     }
    //     else{
    //         temp.push_back(Line(Y[i].x1,s,Y[i].x2,e));
    //         i=j;
    //     }
    // }   
    // // cout<<temp.size()<<endl;
    // Y=temp;



    // cout<<X.size()<<endl;
    // cout<<X[0].x1<<' '<<X[0].x2<<endl;
    int sx = nx, sy = ny, st = t, sd = d;
    if (d == 1 || d == 2){
        // nowl = Y[0];
        for(int i=0;i<Y.size();i++){
            if(Y[i].x1==nx&&Y[i].y1==ny||Y[i].x2==nx&&Y[i].y2==ny){
                nowl=Y[i];
                break;
            }
        }
    }
    else{
        // nowl = X[0];
        for(int i=0;i<X.size();i++){
            if(X[i].x1==nx&&X[i].y1==ny||X[i].x2==nx&&X[i].y2==ny){
                nowl=X[i];
                break;
            }
        }
    }
    while (t)
    {
        cout<<t<<' '<<nx<<' '<<ny<<endl;
        int nextx = nx, nexty = ny;
        bool flag = false;
        switch (d)
        {
        case 1: // 向上走
            for (int i = 0; i < X.size(); i++)
            {
                if (X[i].x1 < nx && nx < X[i].x2 && X[i].y1 > ny && nowl.y2 > X[i].y1)
                {
                    nextx = nx;
                    nexty = X[i].y1;
                    flag = true;
                    nowl = X[i];
                    break;
                }
                if (nowl.y2 <= X[i].y1)
                    break;
            }
            break;
        case 2: // 向下走
            for (int i = X.size() - 1; i >= 0; i--)
            {
                // if(X[i].y1>ny)
                //     break;
                if (X[i].x1 < nx && nx < X[i].x2 && X[i].y1 < ny && nowl.y1 < X[i].y1)
                {
                    nextx = nx;
                    nexty = X[i].y1;
                    flag = true;
                    nowl = X[i];
                    break;
                }
                if (nowl.y1 >= X[i].y1)
                    break;
            }
            break;
        case 3: // 向左走
            for (int i = Y.size() - 1; i >= 0; i--)
            {
                // if(Y[i].x1>nx)
                //     break;
                if (Y[i].y1 < ny && ny < Y[i].y2 && Y[i].x1 < nx && nowl.x1 < Y[i].x1)
                {
                    nextx = Y[i].x1;
                    nexty = ny;
                    flag = true;
                    nowl = Y[i];
                    break;
                }
                if (nowl.x1 >= Y[i].x1)
                    break;
            }
            break;
        case 4: // 向右走
            for (int i = 0; i < Y.size(); i++)
            {
                if (Y[i].y1 < ny && ny < Y[i].y2 && Y[i].x1 > nx && nowl.x2 > Y[i].x1)
                {
                    nextx = Y[i].x1;
                    nexty = ny;
                    flag = true;
                    nowl = Y[i];
                    break;
                }
                if (nowl.x2 <= Y[i].x1)
                    break;
            }
            break;
        }
        if (flag == false)
        { // 掉头
            switch (d)
            {
            case 1: // U
                nexty = nowl.y2;
                if (fabs(nexty - ny) <= t)
                    t -= fabs(nexty - ny),ny = nexty;
                else
                    ny += t,t = 0;
                d = 2;
                break;
            case 2: // D
                nexty = nowl.y1;
                if (fabs(nexty - ny) <= t)
                    t -= fabs(nexty - ny),ny = nexty;
                else
                    ny -= t,t = 0;
                d = 1;
                break;
            case 3: // L
                nextx = nowl.x1;
                if (fabs(nextx - nx) <= t)
                    t -= fabs(nextx - nx),nx = nextx;
                else
                    nx -= t,t = 0;
                d = 4;
                break;
            case 4: // R
                nextx = nowl.x2;
                if (fabs(nextx - nx) <= t)
                {
                    t -= fabs(nextx - nx);
                    nx = nextx;
                }
                else
                {
                    nx += t;
                    t = 0;
                }
                d = 3;
                break;
            }
        }
        else
        {
            if (nextx == nx)
            { // d 1 2
                if (t >= fabs(nexty - ny))
                {
                    t -= fabs(nexty - ny);
                    ny = nexty;
                }
                else
                {
                    if (d == 1)
                        ny += t;
                    else
                        ny -= t;
                    t = 0;
                }
                if (d == 1)
                    d = 3;
                else
                    d = 4;
            }
            else
            { // d 3 4
                if (t >= fabs(nextx - nx))
                {
                    t -= fabs(nextx - nx);
                    nx = nextx;
                }
                else
                {
                    if (d == 3)
                        ny -= t;
                    else
                        ny += t;
                    t = 0;
                }
                if (d == 3)
                    d = 2;
                else
                    d = 1;
            }
        }
        if (nx == sx && ny == sy && sd == d)
        {
            T = st - t;
            t %= T;
        }
    }
    // cout<<T<<endl;
    cout << nx << ' ' << ny;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}