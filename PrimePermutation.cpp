#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
bool primes[N];
string s;
int freq[256];
int main()
{
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) freq[s[i]]++;
	int ind = 0;
	for (int i = 0; i < 256; i++)
		if (freq[i] > freq[ind]) ind = i;
	memset(primes, true, sizeof(primes));
	for (int i = 2; i * i <= n; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j <= n; j += i) primes[j] = false;
		}
	}
	primes[1] = true;
	for (int i = 2; i + i <= n; i++)
		primes[i] = false;
	for (int i = 1; i <= n; i++)
	{
		if (!primes[i])
		{
			if (freq[ind] == 0)
			{
				cout << "NO\n";
				return 0;
			}
			freq[s[i - 1] = ind]--;
		}
	}
	ind = 0;
	for (int i = 1; i <= n; i++)
	{
		if (primes[i])
		{
			while (freq[ind] == 0) ind++;
			freq[s[i - 1] = ind]--;
		}
	}
	cout << "YES\n" << s << "\n";
	return 0;
}