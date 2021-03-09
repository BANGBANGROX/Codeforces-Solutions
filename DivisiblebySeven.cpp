#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int binpow(int a,int b)
{
  int res=1;
  while(b)
  {
    if(b%2==1) res=(res*a)%7;
    a=(a*a)%7;
    b/=2;
  }
  return res;
}
string divby7(string s)
{
  string non0("");
  int n=s.size(),zc=0,oc=0,sc=0,ec=0,nc=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0') zc++;
    else if(s[i]=='1')
    {
      if(oc) non0+=s[i];
      else oc=1;
    }
    else if(s[i]=='6')
    {
      if(sc) non0+=s[i];
      else sc=1;
    }
    else if(s[i]=='8')
    {
      if(ec) non0+=s[i];
      else ec=1;
    }
    else if(s[i]=='9')
    {
      if(nc) non0+=s[i];
      else nc=1;
    }
    else non0+=s[i];
  }
  int m=non0.size(),rem=0,ind=0;
  for(int i=0;i<m;i++)
     rem=(((ll)non0[i]-(ll)'0')*binpow(10,m+zc+4-i-1)+rem)%7;
  string temp="1689";
  int rem1=rem;
  do
  {
    for(int j=0;j<4;j++)
       rem=(rem+((ll)temp[j]-(ll)'0')*binpow(10,4+zc-j-1))%7;
    if(rem==0) 
    {
      non0+=temp;
      break;
    }
    rem=rem1;
  } while(next_permutation(temp.begin(),temp.end()));
  for(int i=0;i<zc;i++) non0+='0';
  return non0;
}
int main()
{
    string s;
    cin>>s;
    cout<<divby7(s)<<"\n";
    return 0;
}