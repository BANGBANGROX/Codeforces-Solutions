#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, allons = 1;
	cin >> n;
	vector<int> val(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
		if (val[i] != 1) allons = 0;
	}
	if (allons)
	{
		for (int i = 1; i < n; i++) cout << 1 << " ";
		cout << 2 << "\n";
		return 0;
	}
	sort(val.begin(), val.end());
	cout << 1 << " ";
	for (int i = 0; i < n - 1; i++) cout << val[i] << " ";
	return 0;
}