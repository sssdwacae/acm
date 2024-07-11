#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 29
using namespace std;

int n, ans, L[MAXN + 10], R[MAXN + 10];
int now[MAXN + 10];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);

    ans = 0;
    memset(now, 0, sizeof(int) * (n + 3));
    for (int i = MAXP; i >= 0; i--) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            int l = now[j] + (1 << i), r = now[j] + (2 << i) - 1;
            // 区间没有交集，答案无法填 1
            if (l > R[j] || r < L[j]) { flag = false; break; }
        }

        if (flag) {
            // 答案可以填 1 的情况
            ans |= 1 << i;
            for (int j = 1; j <= n; j++) now[j] |= 1 << i;
        } else {
            // 答案只能填 0 的情况，看每个数的第 i 位填什么
            for (int j = 1; j <= n; j++) {
                int l = now[j] + (1 << i), r = now[j] + (2 << i) - 1;
                if (l <= R[j] && r >= L[j]) {
                    if (l - 1 < L[j]) now[j] |= 1 << i;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("ansout.txt","w",stdout);
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
/*
8
86 9304
321 2593
559 571
609 5969
743 8949
67 507
191 6943
583 3607
*/