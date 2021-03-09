#include<bits/stdc++.h>
using namespace std;
string s;
int len, ans[1005];
bool dfs(int bwt, int prev, int ind)
{
	if (ind == len) return 1;
	for (int i = 0; i < 10; i++)
	{
		if (ind % 2 == 0)
		{
			if (s[i] == '1' && bwt + i + 1 > 0 && prev != (i + 1) && dfs(bwt + i + 1, i + 1, ind + 1))
			{
				ans[ind] = i + 1;
				return 1;
			}
		}
		else
		{
			if (s[i] == '1' && bwt - i - 1 < 0 && prev != (i + 1) && dfs(bwt - i - 1, i + 1, ind + 1))
			{
				ans[ind] = i + 1;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	cin >> s >> len;
	if (dfs(0, 0, 0))
	{
		cout << "YES\n";
		for (int i = 0; i < len; i++) cout << ans[i] << " ";
	}
	else cout << "NO\n";
	return 0;
}