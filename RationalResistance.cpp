#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll resistors(ll a, ll b)
{
	if (b == 0) return 0;
	ll res = a / b + resistors(b, a % b);
	return res;
}
int main()
{
	ll a, b;
	cin >> a >> b;
	cout << resistors(a, b) << "\n";
	return 0;
}