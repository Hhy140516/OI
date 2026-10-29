#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 3e4 + 5 , INF = 1e9 ;
int n , q ;
vector<int> G[kMaxN] ;
int a[kMaxN] ;
int Fa[kMaxN] , dep[kMaxN] , siz[kMaxN] , son[kMaxN] ; 
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
    siz[u] = siz[v] + 1 ;
    if(siz[son[u]] < siz[v]) son[u] = v ;
  }
}
void dfs2(int u , int t)
{
  top[u] = t ;
  dfn[u] = ++tot ;
  id[tot] = u ;
  if(son[u]) 
  {
    dfs2(son[u] , t) ;
  }
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
    int sum , maxn ;
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
    c[k].maxn = max(c[lson(k)].maxn , c[rson(k)].maxn) ;
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].sum = c[k].maxn = a[id[l]] ;
      return ;
    }
    int mid = l + r >> 1 ;
    build(lson(k) , l , mid) ;
    build(rson(k) , mid + 1 , r) ;
    push_up(k) ;
  }
  void update(int k , int l , int r , int id , int val)
  {
    if(l == r)
    {
      c[k].sum = c[k].maxn = val ;
      return ;
    }
    int mid = l + r >> 1 ;
    if(id <= mid) update(lson(k) , l , mid , id , val) ;
    if(id > mid) update(rson(k) , mid + 1 , r , id , val) ;
    push_up(k) ;
  }
  int query1(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].maxn ;
    }
    int mid = l + r >> 1 ;
    int maxn = -INF ;
    if(L <= mid) maxn = max(maxn , query1(lson(k) , l , mid , L , R)) ;
    if(R > mid) maxn = max(maxn , query1(rson(k) , mid + 1 , r , L , R)) ;
    return maxn ;
  }
  int query2(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].sum ;
    }
    int mid = l + r >> 1 ;
    int sum = 0 ;
    if(L <= mid) sum += query2(lson(k) , l , mid , L , R) ;
    if(R > mid) sum += query2(rson(k) , mid + 1 , r , L , R) ;
    return sum ;
  }
};
cTr Tr ;
int get1(int x , int y)
{
  int maxn = -INF ;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    maxn = max(maxn , Tr.query1(1 , 1 , n , dfn[top[x]] , dfn[x])) ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  maxn = max(maxn , Tr.query1(1 , 1 , n , dfn[x] , dfn[y])) ;
  return maxn ;
}
int get2(int x , int y)
{
  int sum = 0 ;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    sum += Tr.query2(1 , 1 , n , dfn[top[x]] , dfn[x]) ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  sum += Tr.query2(1 , 1 , n , dfn[x] , dfn[y]) ;
  return sum ;
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
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  dfs1(1 , 0) ;
  dfs2(1 , 1) ;
  Tr.build(1 , 1 , n) ;
  cin >> q ;
  while(q--)
  {
    string s ;
    cin >> s ;
    if(s == "CHANGE")
    {
      int u , w ;
      cin >> u >> w ;
      Tr.update(1 , 1 , n , dfn[u] , w) ;
    }
    else if(s == "QMAX")
    {
      int u , v ;
      cin >> u >> v ;
      cout << get1(u , v) << "\n" ;
    }
    else
    {
      int u , v ;
      cin >> u >> v ;
      cout << get2(u , v) << "\n" ;
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