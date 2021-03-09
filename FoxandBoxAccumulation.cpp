#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,arr[1001],piles=0,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int brr[1001]={0};
    sort(arr,arr+n);
    vector<int> res;
    while(cnt<n)
    {
      piles++;
      for(int i=0;i<n;i++)
      {
         if(arr[i]>=(int)res.size() && !brr[i])
         {
             res.push_back(arr[i]);
             brr[i]=1;
             cnt++;
         }
      }
         res.clear();
    }
    cout<<piles<<"\n";
    return 0;
}