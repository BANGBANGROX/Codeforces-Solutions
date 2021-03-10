#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> tree[N];
bool val1[N], val2[N];
int par[N], n;
set<int> res;
vector<int> chosen(N, 0);
void dfs(int node, int gf, int p)
{
	par[node] = p;
	bool eff = 0;
	if (gf != -1 && chosen[gf] % 2)
	{
		eff = 1;
		if (chosen[gf]) chosen[node]++;
	}
	if (val1[node] == val2[node] && eff)
	{
		chosen[node]++;
		res.insert(node);
	}
	else if (val1[node] != val2[node] && !eff)
	{
		chosen[node]++;
		res.insert(node);
	}
	for (int child : tree[node])
	{
		if (child != p) dfs(child, par[node], node);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) cin >> val1[i];
	for (int i = 1; i <= n; i++) cin >> val2[i];
	dfs(1, -1, -1);
	cout << res.size() << "\n";
	for (int x : res) cout << x << "\n";
	return 0;
}
