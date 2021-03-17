#include<bits/stdc++.h>
using namespace std;
int dp[2][2000005], n, w, wts[505], vals[505];
int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++) cin >> vals[i] >> wts[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i % 2)
			{
				if (wts[i] <= j) dp[1][j] = max(dp[0][j], vals[i] + dp[0][j - wts[i]]);
				else dp[1][j] = dp[0][j];
			}
			else
			{
				if (wts[i] <= j) dp[0][j] = max(dp[1][j], vals[i] + dp[1][j - wts[i]]);
				else dp[0][j] = dp[1][j];
			}
		}
	}
	if (n % 2) cout << dp[1][w] << "\n";
	else cout << dp[0][w] << "\n";
	return 0;
}