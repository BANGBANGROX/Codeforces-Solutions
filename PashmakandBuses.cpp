#include<bits/stdc++.h>
using namespace std;
int n, k, d;
int main()
{
	cin >> n >> k >> d;
	int res = 1, val = 1;
	while (res < n && val <= d)
	{
		res *= k;
		val++;
	}
	if (res < n)
	{
		cout << -1 << "\n";
		return 0;
	}
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) ans[i] = i;
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ans[j] % k + 1 << " ";
			ans[j] /= k;
		}
		cout << "\n";
	}
	return 0;
}