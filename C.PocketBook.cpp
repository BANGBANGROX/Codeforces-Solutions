#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;
    set<char> poss[1000];
    for(int i=0;i<n;i++)
    {
       char ch;
       for(int j=0;j<m;j++)
       {
           cin>>ch;
           poss[j].insert(ch);
       }
    }
    ll res=1;
    for(int i=0;i<m;i++)
      res=(res*(ll)poss[i].size())%mod;
    cout<<res<<"\n";
    return 0;
}