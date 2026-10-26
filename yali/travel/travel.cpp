#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 1e9 + 7 ;
int n ;
int val[1000005] ;
vector<int> G[1000005] ;
int siz[1000005] ;
struct node
{
  int x , id ;
  bool operator < (const node &a) const
  {
    if(x == a.x) return id < a.id ;
    return x < a.x ;
  }
}nd[1000005] ;
ll sum , as ;
void dfs(int u , int fa)
{
  siz[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa) continue ;
    dfs(v , u) ;
    siz[u] += siz[v] ;
    sum += 1ll * siz[v] * (n - siz[v]) % MOD ;
    sum %= MOD ;
  }
}
struct dsu
{
  vector<int> fa , siz ;
  dsu()
  {
    fa.resize(n + 2) ;
    siz.resize(n + 2) ;
    for( int i = 1 ; i <= n ; i++ )
    {
      fa[i] = i , siz[i] = 1 ;
    }
  }
  int find(int x)
  {
    if(fa[x] == x) return x ;
    fa[x] = find(fa[x]) ;
    return fa[x] ;
  }
  void unionn(int x , int y)
  {
    x = find(x) , y = find(y) ;
    if(x != y) 
    {
      fa[y] = x ;
      siz[x] += siz[y] ;
    }
  }
  bool check(int x , int y)
  {
    return find(x) == find(y) ;
  }
};
void solve()
{ 
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    cin >> val[i] ;
    nd[i] = {val[i] , i} ;
  }
  sort(nd + 1 , nd + n + 1) ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  dfs(1 , 0) ;
  sum = sum * 2 % MOD ;
  dsu D ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int u = nd[i].id ;
    for( int j = 0 ; j < G[u].size() ; j++ )
    {
      int v = G[u][j] ;
      if(val[u] < val[v] || (val[u] == val[v] && u < v)) continue ;
      as += D.siz[D.find(u)] * 2ll % MOD * D.siz[D.find(v)] % MOD * val[u] % MOD ;
      as %= MOD ;
      D.unionn(u , v) ;
    }
  }
  // cout << as << " " << sum << "\n" ;
  cout << (as - sum + MOD) % MOD ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("travel.in" , "r" , stdin) ;
  freopen("travel.out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}
