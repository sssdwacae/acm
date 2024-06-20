// 把键盘输入的n个数用选择法排序。输出输入严格按照样张。
#include <iostream>
using namespace std;
int main()
{
    const int N = 20;
    int i, j, p, n, m, a[N];
    cout << "请输入欲排序数据的个数:";
    cin >> n;
    cout << "请输入需排序的" << n << "个数：";
    for (i = 0; i < n; i++)
        cin >> a[i];
    /****************************/
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[i] > a[j])
            {
                p = a[i];
                a[i] = a[j];
                a[j] = p;
            }
        }
    }

    /****************************/
    cout << "排序后的" << n << "个数为:" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}