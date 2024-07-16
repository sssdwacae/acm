#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair

void solve()
{
    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        switch (temp)
        {
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        case 3:
            cnt1++;
            cnt2++;
            break;
        case 4:
            cnt1--;
            cnt2--;
        }
    }
    if (cnt1 > cnt2)
        cout << "Kobayashi\n";
    else if (cnt1 < cnt2)
        cout << "Tohru\n";
    else
        cout << "Draw\n";
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