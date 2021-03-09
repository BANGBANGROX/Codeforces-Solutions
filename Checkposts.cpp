#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
vector<int> graph[N], invgraph[N], order;
bool vis1[N], vis2[N];
int n, m, minval = INT_MAX, cnt, val[N];
void dfs1(int node)
{
	vis1[node] = 1;
	for (int child : graph[node])
		if (!vis1[child]) dfs1(child);
	order.push_back(node);
}
void dfs2(int node)
{
	vis1[node] = 1;
	minval = min(minval, val[node]);
	for (int child : invgraph[node])
		if (!vis1[child]) dfs2(child);
}
void dfs3(int node)
{
	vis2[node] = 1;
	if (val[node] == minval) cnt++;
	for (int child : invgraph[node])
		if (!vis2[child]) dfs3(child);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		invgraph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!vis1[i]) dfs1(i);
	memset(vis1, 0, sizeof(vis1));
	reverse(order.begin(), order.end());
	ll res = 1, mincost = 0;
	for (int v : order)
	{
		if (!vis1[v])
		{
			dfs2(v);
			dfs3(v);
			mincost += (ll)minval;
			res = (res * (ll)cnt) % mod;
			cnt = 0;
			minval = INT_MAX;
		}
	}
	cout << mincost << " " << res << "\n";
	return 0;
}
