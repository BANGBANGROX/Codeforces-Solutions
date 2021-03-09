#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> arr(n), left(n), right(n), incr(n, 1), decr(n, 1);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ptr = 0;
	left[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= arr[i - 1]) incr[i]++;
		if (arr[i] > arr[i - 1]) ptr = i;
		left[i] = ptr;
	}
	right[n - 1] = n - 1;
	ptr = n - 1;
	for (int i = n - 2; i > -1; i--)
	{
		if (arr[i] >= arr[i + 1]) decr[i]++;
		if (arr[i] > arr[i + 1]) ptr = i;
		right[i] = ptr;
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (incr[r] == (r - l + 1) || decr[r] == (r - l + 1) || right[l] >= left[r]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}