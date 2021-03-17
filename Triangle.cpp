#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<pair<int, int>> triples[N];
pair<int, int> p1, p2, p3;
int a, b;
bool isps(int x)
{
	return (double)sqrt(x) == floor(sqrt(x));
}
void pyt()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (isps(i * i - j * j))
			{
				triples[i].push_back({ j,sqrt(i * i - j * j) });
			}
		}
	}
}
bool triangle()
{
	for (pair<int,int> d1 : triples[a])
	{
		int ad1 = d1.first, ad2 = d1.second;
		for (pair<int, int> d2 : triples[b])
		{
			int bd1 = d2.first, bd2 = d2.second;
			if (min(ad1, ad2) * max(bd1, bd2) == min(bd1, bd2) * max(ad1, ad2))
			{
				p1 = { 1,1 };
				p2 = { 1 + ad2,1 + ad1 };
				p3 = { 1 - bd1,1 + bd2 };
				if (p2.second == p3.second) p3 = { 1 + bd1,1 - bd2 };
				return 1;
			}
		}
    }
	return 0;
}
int main()
{
	pyt();
	cin >> a >> b;
	if (triangle()) cout << "YES\n" << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n" << p3.first << " " << p3.second << "\n";
	else cout << "NO\n";
	return 0;
}