#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct events
{
    int l,r;
};
events e[N];
bool comp(events a,events b)
{
    return a.l<b.l;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>e[i].l>>e[i].r;
    sort(e,e+n,comp);
    int minl=e[0].l,maxr=e[0].r,ans=0;
    for(int i=1;i<n;i++)
    {
        if(e[i].l>minl && e[i].r<maxr) ans++;
        if(e[i].r>maxr) maxr=e[i].r,minl=e[i].l;    
    }
    cout<<ans<<"\n";
    return 0;
}