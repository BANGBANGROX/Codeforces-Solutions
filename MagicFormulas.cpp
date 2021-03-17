#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, val = 0, x, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		val ^= x;
	}
	vector<int> xors(n + 1, 0);
	for (int i = 1; i <= n; i++) xors[i] = xors[i - 1] ^ i;
	for (int i = 2; i <= n; i++)
	{
		int t = n / i;
		if (t % 2 == 0) val ^= xors[n % i];
		else val = val ^ xors[n % i] ^ xors[i - 1];
	}
	printf("%d", val);
	return 0;
}