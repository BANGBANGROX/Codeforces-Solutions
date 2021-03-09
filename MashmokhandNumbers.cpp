#include<bits/stdc++.h>
using namespace std;
int n, k;
void solve()
{
	set<int> vis;
	if (k < n / 2 || (n == 1 && k > 0))
	{
		cout << -1 << "\n";
		return;
	}
	if (k == n / 2)
	{
		for (int i = 1; i <= n; i++) cout << i << " ";
		return;
	}
	int pairs = n / 2 - 1, gcd = k - pairs;
	cout << gcd << " " << gcd * 2 << " ";
	vis.insert(gcd);
	vis.insert(gcd * 2);
	int prev = gcd + 1;
	if (gcd == 1) prev = 3;
	for (int i = 3; i <= n; i++)
	{
		if (vis.find(prev) != vis.end())
		{
			if (prev % 2) prev += 2;
			else prev++;
	    }
		vis.insert(prev);
		cout << prev++ << " ";
	}
}
int main()
{
	cin >> n >> k;
	solve();
	return 0;
}
