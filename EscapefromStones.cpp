#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin >> s;
	vector<int> lres, rres;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'l') lres.push_back(i + 1);
		else rres.push_back(i + 1);
	}
	for (int i = 0; i < (int)rres.size(); i++) cout << rres[i] << "\n";
	for (int i = (int)lres.size() - 1; i > -1; i--) cout << lres[i] << "\n";
	return 0;
}