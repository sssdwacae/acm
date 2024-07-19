#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 5;
#define ll long long
#define mp make_pair

bool isprime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

const int MAXN = 1e6;
int prime[MAXN + 1];
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

// <=x
int mid(int l, int r, int x)
{
    while (l < r)
    {
        int mid = (l + 1 + r) / 2;
        if (prime[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }

    return l;
}
int cnt = 0;
void solve()
{
    // for(int i=2;i<=1e6;i++){
    //     if(isprime(i))
    //         cout<<i<<' ';
    // }
    cout << "Case " << ++cnt << ": ";
    int x, y, k, w;
    cin >> x >> y >> k >> w;
    int l = mid(1, prime[0], k);
    // if (prime[l] == k)
    // { // k是素数

    // }
    // else
    // { // k不是素数

    int mn = min(x, y) - k - w; // Bob把最小值减到k的步骤  Alice最多能动几步

    // 找max(x,y)-mn  -  max(x,y)有没有素数
    int find = prime[mid(1, prime[0], max(x, y))];
    if (max(x, y) - mn <= find)
    { // 有
        if (find == k)
            cout << "Bob\n";
        else
        {
            int pos = max(x, y) - find; // Alice 把最大值减为素数的步数
            // minn -k
            int find2 = prime[mid(1, prime[0], min(x, y))];
            if (find2 < k)
                cout << "Bob\n";
            else
            {
                int po1 = max(x, y) - find;
                int po2 = min(x, y) - find2;
                if (w == 0 && (po1 + po2) % 2 == 1 || w == 1 && (po1 + po2) % 2 == 0)
                    cout << "Alice\n";
                else
                    cout << "Bob\n";
            }
        }
    }
    else
    {
        cout << "Bob\n";
    }
    // }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getPrime();
    // cout<<mid(1,prime[0],1);
    int T;
    cin >> T;
    // T = 1;

    // cout<<prime[0];
    // for (int i = 0; i <= MAXN; i++)
    //     cout<<prime[i]<<' ';
    while (T--)
        solve();
    return 0;
}