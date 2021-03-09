#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,minval=4444444444;
bool flag;
set<ll> lnums;
void lucky(ll x)
{
    if(x>=r)
    {
       minval=min(minval,x);
       return;
    }
    if(x>=l) lnums.insert(x);
    lucky(10*x+4);
    lucky(10*x+7);
}
int main()
{
    cin>>l>>r;
    lucky(4);
    lucky(7);
    lnums.insert(minval);
    ll prev=l,res=0,last=-1;
    for(ll curr:lnums)
    {
       res=(res+(curr-prev+1)*curr);
       prev=curr+1;
       last=curr;
    }
    if(last!=-1) res=(res+(r-prev+1)*last);
    cout<<res<<"\n";
    return 0;
}