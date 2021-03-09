#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1e6+5;
ll fact[N],a,b,n;
ll binpow(ll a, ll b)
{
   ll res=1;
   while(b)
   {
       if(b%2==1) res=(res*a)%mod;
       a=(a*a)%mod;
       b/=2;
   }
   return res;
}
void factorial()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
      fact[i]=((ll)i*fact[i-1])%mod;
}
ll ncr(ll n,ll r)
{
    if(r>n) return 0;
    ll res=(fact[n]*binpow(fact[n-r],mod-2)%mod*binpow(fact[r],mod-2))%mod;
    return res;
}
bool islucky(ll num)
{
    while(num)
    {
       ll x=num%10;
       if(x!=a && x!=b) return false;
       num/=10;
    }
    return true;
}
int main()
{
    factorial();
    cin>>a>>b>>n;
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        ll sum=a*i+b*(n-i);
        if(islucky(sum))
          res=(res+ncr(n,(ll)i))%mod;
    }
    cout<<res<<"\n";
    return 0;
}