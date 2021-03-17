#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
string thegirl()
{
	ll lcm = (a * b) / gcd(a, b), val1 = lcm / a, val2 = lcm / b;
	if (a > b)
	{
		if (val2 - 1 < val1) return "Dasha";
		if (val1 < val2 - 1) return "Masha";
		return "Equal";
	}
	else
	{
		if (val1 - 1 > val2) return "Dasha";
		if (val2 > val1 - 1) return "Masha";
	}
	return "Equal";
}
int main()
{
	cin >> a >> b;
	cout << thegirl() << "\n";
	return 0;
}