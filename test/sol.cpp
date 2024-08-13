#include <bits/stdc++.h>
using namespace std;
int c[1005];
int main()
{
	int n;
	cin >> n;
	c[1004] = 1;
	int temp=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1004; j >= 0; j--)
		{
			int k=c[j]*2+temp;
			c[j]=k%10;
			temp=k/10;
		}
	}
	c[1004]--;
	temp =0;
	for (int j = 1004; j >= 0; j--)
		{
			int k=c[j]*2+temp;
			c[j]=k%10;
			temp=k/10;
		}
	bool flag = 1;
	for (int i = 0; i < 1005; i++)
	{
		if (c[i] == 0 && flag)
		{
			continue;
		}
		else
		{
			flag = 0;
			cout << c[i];
		}
	}
	return 0;
}