#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, winningmove = 0;
bool winner()
{
	map<ll, ll> fact;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll cnt = 0;
			while (n % i == 0)
			{
				cnt++;
				n /= i;
			}
			fact[i] = cnt;
		}
	}
	if (n > 1) fact[n] = 1;
	ll psum = 0, prod = 1, cnt = 0;
	bool res = 0;
	for (pair<ll, ll> temp : fact)
	{
		cnt++;
		psum += temp.second;
		prod *= temp.first;
		if (psum >= 2 && cnt==2) winningmove = prod;
		if (cnt == 1 && psum >= 2) winningmove = temp.first * temp.first;
	}
	if (psum != 2) res = 1;
	return res;
}
int main()
{
	cin >> n;
	if (winner()) cout << 1 << "\n" << winningmove << "\n";
	else cout << 2 << "\n";
	return 0;
}
