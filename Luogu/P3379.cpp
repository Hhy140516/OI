#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n , m , s ;
vector<int> G[kMaxN] ;
int Fa[kMaxN] , siz[kMaxN] , son[kMaxN] , dep[kMaxN] ;
int top[kMaxN] ;
void dfs1(int u , int fa)
{
  dep[u] = dep[fa] + 1 ;
  Fa[u] = fa ;
  siz[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa) continue ;
    dfs1(v , u) ;
    siz[u] += siz[v] ;
    if(siz[son[u]] < siz[v]) son[u] = v ;
  }
}
void dfs2(int u , int fa , int t)
{
  top[u] = t ;
  if(son[u]) dfs2(son[u] , u , t) ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa || v == son[u]) continue ;
    dfs2(v , u , v) ;
  }
}
int lca(int u , int v)
{
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  return u ;
}
void solve()
{ 
  cin >> n >> m >> s ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  dfs1(s , 0) ;
  dfs2(s , 0 , s) ;
  while(m--)
  {
    int x , y ;
    cin >> x >> y ;
    cout << lca(x , y) << "\n" ;
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