#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
struct node
{
  int v , w ;
};
vector<node> G[5005] ;
bool vis[5005] ;
int d[5005] , cn[5005] ;
bool spfa(int s)
{
  queue<int> q ;
  q.push(s) ;
  vis[s] = 1 ;
  memset(d , 0x3f , sizeof d) ;
  d[s] = 0 ;
  while(!q.empty())
  {
    int u = q.front() ;
    q.pop() ;
    vis[u] = 0 ;
    for( int i = 0 ; i < G[u].size() ; i++ )
    {
      int v = G[u][i].v , w = G[u][i].w ;
      if(d[v] > d[u] + w) 
      {
        d[v] = d[u] + w ;
        cn[v] = cn[u] + 1 ;
        if(cn[v] > n)
        {
          return 1 ;
        }
        if(!vis[v])
        {
          vis[v] = 1 ;
          q.push(v) ;
        }
      }
    }
  }
  return 0 ;
}
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    G[0].push_back({i , 0}) ;
  }
  for( int i = 1 ; i <= m ; i++ )
  {
    int u , v , w ;
    cin >> u >> v >> w ;
    G[v].push_back({u , w}) ;
  }
  bool fl = spfa(0) ;
  if(fl) cout << "NO" ;
  else 
  {
    for( int i = 1 ; i <= n ; i++ ) cout << d[i] << " " ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}