#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n, d, l = 1, r = 3;
	cin >> n >> d;
	vector<int> pts(n + 1);
	for (int i = 1; i <= n; i++) cin >> pts[i];
	ll res = 0;
	while (l <= n && r <= n)
	{
		if (pts[r] - pts[l] <= d)
		{
			ll val = ((ll)r - l - 1);
			res += val * (val + 1) / 2;
			r++;
		}
		else l++;
	}
	cout << res << "\n";
	return 0;
}

