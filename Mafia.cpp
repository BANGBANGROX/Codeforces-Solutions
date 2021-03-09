#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, sum = 0, x, maxx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
		maxx = max(maxx, x);
	}
	ll res = sum / (n - 1);
	if (sum % (n - 1)) res++;
	cout << max(maxx, res) << "\n";
	return 0;
}
