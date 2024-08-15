#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Contest {
    double gain;
    int p;
};

// 计算单个比赛的增益
double calculate_gain(double k, double r, int p) {
    return k * p + (1.0 - k) * r - r;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        double k;
        cin >> n >> m >> k;
        
        int r0;
        cin >> r0;
        
        vector<int> p(n);
        vector<Contest> contests(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            contests[i] = {calculate_gain(k, r0, p[i]), p[i]};
        }
        
        // 对比赛按照增益从小到大排序
        sort(contests.begin(), contests.end(), [](const Contest& a, const Contest& b) {
            return a.gain < b.gain;
        });
        
        double r = r0;
        // 前 m 个比赛不评分
        for (int i = m; i < n; ++i) {
            r = k * contests[i].p + (1.0 - k) * r;
        }
        
        cout << fixed << setprecision(20) << r << endl;
    }
    
    return 0;
}
