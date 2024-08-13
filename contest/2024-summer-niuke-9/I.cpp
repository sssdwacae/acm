#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Point {
    long long x, y;
    Point operator+(const Point &other) const {
        return {x + other.x, y + other.y};
    }
};

double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

std::vector<Point> convexHull(std::vector<Point> &points) {
    int n = points.size(), k = 0;
    if (n == 1) return points;
    std::vector<Point> hull(2 * n);
    
    std::sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });
    
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    
    hull.resize(k - 1);
    return hull;
}

double polygonPerimeter(const std::vector<Point> &polygon) {
    double perimeter = 0.0;
    for (size_t i = 0; i < polygon.size(); ++i) {
        size_t j = (i + 1) % polygon.size();
        double dx = polygon[i].x - polygon[j].x;
        double dy = polygon[i].y - polygon[j].y;
        perimeter += std::sqrt(dx * dx + dy * dy);
        cout<<perimeter<<endl;
    }
    return perimeter;
}

int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int n, m;
        std::cin >> n;
        std::vector<Point> A(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> A[i].x >> A[i].y;
        }
        
        std::cin >> m;
        std::vector<Point> B(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> B[i].x >> B[i].y;
        }
        
        std::vector<Point> minkowskiSum;
        for (const auto &a : A) {
            for (const auto &b : B) {
                minkowskiSum.push_back(a + b);
            }
        }
        
        std::vector<Point> convexHullPoints = convexHull(minkowskiSum);
        double result = polygonPerimeter(convexHullPoints);
        cout<<result<<endl;
        std::cout.precision(12);
        std::cout << std::fixed << result << std::endl;
    }
    
    return 0;
}
