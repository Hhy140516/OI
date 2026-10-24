#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int n , q ;
vector<int> G[kMaxN] ;
int dep[kMaxN] , siz[kMaxN] , Fa[kMaxN] , son[kMaxN] ;
int top[kMaxN] , dfn[kMaxN] , id[kMaxN] , tot ;
void dfs1(int u , int fa)
{
  Fa[u] = fa ;
  dep[u] = dep[fa] + 1 ;
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
void dfs2(int u , int t)
{
  top[u] = t ;
  dfn[u] = ++tot ;
  id[tot] = u ;
  if(son[u]) dfs2(son[u] , t) ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == Fa[u] || v == son[u]) continue ;
    dfs2(v , v) ;
  }
}
struct cTr
{
  struct node
  {
    ll sum , lazy ;
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 2) ;
  }
  inline int lson(int k)
  {
    return k << 1 ;
  }
  inline int rson(int k)
  {
    return k << 1 | 1 ;
  }
  void push_up(int k)
  {
    c[k].sum = c[lson(k)].sum + c[rson(k)].sum ;
  }
  void push_down(int k , int l , int r)
  {
    if(c[k].lazy == 0) return ;
    int mid = l + r >> 1 ;
    c[lson(k)].sum += (mid - l + 1) * c[k].lazy ;
    c[lson(k)].lazy += c[k].lazy ;
    c[rson(k)].sum += (r - mid) * c[k].lazy ;
    c[rson(k)].lazy += c[k].lazy ;
    c[k].lazy = 0 ;
  }
  void update(int k , int l , int r , int L , int R , ll d)
  {
    if(L <= l && r <= R)
    {
      c[k].sum += (r - l + 1) * d ;
      c[k].lazy += d ;
      return ;
    }
    int mid = l + r >> 1 ;
    push_down(k , l , r) ;
    if(L <= mid) update(lson(k) , l , mid , L , R , d) ;
    if(R > mid) update(rson(k) , mid + 1 , r , L , R , d) ;
    push_up(k) ;
  } 
  ll query(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].sum ;
    }
    push_down(k , l , r) ;
    int mid = l + r >> 1 ;
    ll as = 0 ;
    if(L <= mid) as += query(lson(k) , l , mid , L , R) ;
    if(R > mid) as += query(rson(k) , mid + 1 , r , L , R) ;
    return as ;
  }
};
cTr Tr ;
void change(int u , int v , ll d)
{
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    Tr.update(1 , 1 , n , dfn[top[u]] , dfn[u] , d) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  Tr.update(1 , 1 , n , dfn[u] , dfn[v] , d) ;
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    u++ , v++ ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  dfs1(1 , 0) ;
  dfs2(1 , 1) ;
  cin >> q ;
  while(q--)
  {
    char c ;
    cin >> c ;
    if(c == 'A')
    {
      int u , v , d ;
      cin >> u >> v >> d ;
      u++ , v++ ;
      change(u , v , d) ;
    }
    else
    {
      int u ;
      cin >> u ;
      u++ ;
      cout << Tr.query(1 , 1 , n , dfn[u] , dfn[u] + siz[u] - 1) << "\n" ;
    }
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