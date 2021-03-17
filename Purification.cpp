#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
char grid[N][N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> grid[i][j];
	int cnt = 0;
	vector<pair<int, int>> resr;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (grid[i][j] == '.')
			{
				resr.push_back({ i,j });
				cnt++;
				break;
			}
		}
	}
	if (cnt != n)
	{
		cnt = 0;
		vector<pair<int, int>> resc;
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (grid[i][j] == '.')
				{
					resc.push_back({ i,j });
					cnt++;
					break;
				}
			}
		}
		if (cnt == n) for (pair<int, int> temp : resc) cout << temp.first << " " << temp.second << "\n";
		else cout << -1 << "\n";
	}
	else for (pair<int, int> temp : resr) cout << temp.first << " " << temp.second << "\n";
	return 0;
}