#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 3e5 + 5 , MOD = 998244353 ;
int n , q ;
vector<int> G[kMaxN] ;
int dep[kMaxN] , Fa[kMaxN] , siz[kMaxN] , son[kMaxN] ;
int top[kMaxN] , dfn[kMaxN] , id[kMaxN] , tot ;
ll ksm(ll a , ll b)
{
  ll mul = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a % MOD ;
    a = a * a % MOD ;
    b >>= 1 ;
  }
  return mul ;
}
void dfs1(int u , int fa)
{
  Fa[u] = fa ;
  siz[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa) continue ;
    dep[v] = dep[u] + 1 ;
    dfs1(v , u) ;
    siz[u] += siz[v] ;
    if(siz[v] > siz[son[u]])
    {
      son[u] = v ;
    }
  }
}
void dfs2(int u , int fa , int t)
{
  top[u] = t ;
  dfn[u] = ++tot ;
  id[tot] = u ;
  if(son[u])
  {
    dfs2(son[u] , u , t) ;
  }
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa || v == son[u]) continue ;
    dfs2(v , u , v) ;
  }
}
ll s[55][kMaxN] ;
ll get(int x , int y , int B)
{
  ll as = 0 ;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    as = (as + s[B][dfn[x]] - s[B][dfn[top[x]] - 1] + MOD) % MOD ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  as = (as + s[B][dfn[y]] - s[B][dfn[x] - 1] + MOD) % MOD ;
  return as ;
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  dfs1(1 , 0) ;
  dfs2(1 , 0 , 1) ;
  for( int i = 1 ; i <= 50 ; i++ ) 
  {
    for( int j = 1 ; j <= n ; j++ )
    {
      s[i][j] = ksm(dep[id[j]] , i) ;
      s[i][j] = (s[i][j] + s[i][j - 1]) % MOD ;
    }
  }
  cin >> q ;
  while(q--)
  {
    int x , y , k ;
    cin >> x >> y >> k ;
    cout << get(x , y , k) << "\n" ;
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