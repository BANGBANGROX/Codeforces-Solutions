#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
struct pts
{
    int x,y;
};
pts p[1001];
void dfs(int node)
{
    vis[node]=1;
    for(int child:adj[node])
    {
        if(!vis[child]) dfs(child);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>p[i].x>>p[i].y;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(p[i].x==p[j].x||p[i].y==p[j].y) 
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int cc=-1;
    for(int i=1;i<=n;i++)
    {
       if(!vis[i])
       {
           cc++;
           dfs(i);
       }
    }
    cout<<cc<<"\n";
    return 0;
}