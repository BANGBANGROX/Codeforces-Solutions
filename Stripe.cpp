#include<bits/stdc++.h>
using namespace std;
int n, arr[100005];
int findways()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += arr[i];
	if (sum % 2) return 0;
	int ans = 0, cnt = 0, tempsum = 0;
	for (int i = 1; i <= n; i++)
	{
		tempsum += arr[i];
		if (tempsum == sum)
		{
			ans += cnt;
			cnt = 0;
		}
		if (tempsum == sum / 2) cnt++;
	}
	return ans;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	cout << findways() << "\n";
	return 0;
}
