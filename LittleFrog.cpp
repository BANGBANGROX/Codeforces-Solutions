#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	cout << 1 << " " << n << " ";
	int diff = n - 2, prev = n;
	for (int i = 3; i <= n; i++)
	{  
		int curr = prev + diff;
		if (i % 2) curr = prev - diff;
		cout << curr << "\n";
		prev = curr;
		diff--;
	}
	return 0;
}
