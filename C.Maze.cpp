#include<bits/stdc++.h>
using namespace std;
int n,m,dx[]={-1,0,1,0},dy[]={0,-1,0,1},vis[1001][1001],k;
char grid[1001][1001];
vector<pair<int,int>> dfs;
bool isvalid(int x,int y)
{
    return x>0 && x<=n && y>0 && y<=m && vis[x][y]==0 && grid[x][y]=='.';
}
void DFS(int x,int y)
{
   dfs.push_back({x,y});
   vis[x][y]=1;
   for(int i=0;i<4;i++)
   {
       if(isvalid(x+dx[i],y+dy[i]))
         DFS(x+dx[i],y+dy[i]);
   }
}
int main()
{
    cin>>n>>m>>k;
    int posx=-1,posy=-1;
    for(int i=1;i<=n;i++)
    { 
       for(int j=1;j<=m;j++)
       {
           cin>>grid[i][j];
           if(grid[i][j]=='.' && posx==-1) posx=i,posy=j;
       }
    }
    DFS(posx,posy);
    reverse(dfs.begin(),dfs.end());
    for(int i=0;i<k;i++)
       grid[dfs[i].first][dfs[i].second]='X';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
          cout<<grid[i][j];
        cout<<"\n";
    }
    return 0;
}