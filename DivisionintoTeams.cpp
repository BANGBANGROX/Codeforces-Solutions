#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, maxel = 0, sumx = 0, sumy = 0, x;
	cin >> n;
	vector<pair<int, int>> ratings;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		maxel = max(maxel, x);
		ratings.push_back({ x,i });
	}
	sort(ratings.begin(), ratings.end());
	vector<pair<int, int>> teamx, teamy;
	for (int i = n - 1; i > -1; i--)
	{
		if (i % 2)
		{
			teamy.push_back(ratings[i]);
			sumy += ratings[i].first;
		}
		else
		{
			teamx.push_back(ratings[i]);
			sumx += ratings[i].first;
		}
	}
	if (abs(sumx - sumy) > maxel)
	{
		auto temp = teamx[0];
		teamx.erase(teamx.begin());
		teamy.push_back(temp);
	}
	cout << teamx.size() << "\n";
	for (auto temp : teamx) cout << temp.second + 1 << " ";
	cout << "\n" << teamy.size() << "\n";
	for (auto temp : teamy) cout << temp.second + 1 << "\n";
	return 0;
}
