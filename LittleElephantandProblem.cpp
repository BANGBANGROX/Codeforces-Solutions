#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n),brr(n);
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(brr.begin(),brr.end());
    int diff=0;
    for(int i=0;i<n;i++)
      if(arr[i]!=brr[i]) diff++;
    if(diff>2) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}