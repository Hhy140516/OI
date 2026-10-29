#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int n ;
struct node
{
  int v , w ;
};
struct edge
{
  int u , v ;
}edg[kMaxN] ;
vector<node> G[kMaxN] ;
int Fa[kMaxN] , a[kMaxN] , dep[kMaxN] , siz[kMaxN ] , son[kMaxN] ;
int top[kMaxN] , id[kMaxN] , dfn[kMaxN] , tot ;
void dfs1(int u , int fa)
{
  dep[u] = dep[fa] + 1 ;
  Fa[u] = fa ;
  siz[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i].v , w = G[u][i].w ;
    if(v == fa) continue ;
    a[v] = w ;
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
  if(son[u])
  {
    dfs2(son[u] , t) ;
  }
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i].v ;
    if(v == Fa[u] || v == son[u]) continue ;
    dfs2(v , v) ;
  }
}
struct cTr
{
  struct node
  {
    int maxn , lazy1 , lazy2 ;
    node()
    {
      lazy1 = -1 ;
    }
  } ;
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
    c[k].maxn = max(c[lson(k)].maxn , c[rson(k)].maxn) ;
  }
  void push_down(int k)
  {
    if(c[k].lazy1 != -1)
    {
      c[lson(k)].maxn = c[k].lazy1 ;
      c[lson(k)].lazy1 = c[k].lazy1 ;
      c[lson(k)].lazy2 = 0 ;
      c[rson(k)].maxn = c[k].lazy1 ;
      c[rson(k)].lazy1 = c[k].lazy1 ;
      c[rson(k)].lazy2 = 0 ;
      c[k].lazy1 = -1 ;
    }
    if(c[k].lazy2)
    {
      c[lson(k)].maxn += c[k].lazy2 ;
      c[lson(k)].lazy2 += c[k].lazy2 ;
      c[rson(k)].maxn += c[k].lazy2 ;
      c[rson(k)].lazy2 += c[k].lazy2 ;
      c[k].lazy2 = 0 ;
    }
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].maxn = a[id[l]] ;
      return ;
    }
    int mid = l + r >> 1 ;
    build(lson(k) , l , mid) ;
    build(rson(k) , mid + 1 , r) ;
    push_up(k) ;
  }
  void update1(int k , int l , int r , int L , int R , int val)
  {
    if(L <= l && r <= R)
    {
      c[k].maxn = val ;
      c[k].lazy1 = val ;
      c[k].lazy2 = 0 ;
      return ;
    }
    int mid = l + r >> 1 ;
    push_down(k) ;
    if(L <= mid) update1(lson(k) , l , mid , L , R , val) ;
    if(R > mid) update1(rson(k) , mid + 1 , r , L , R , val) ;
    push_up(k) ;
  }
  void update2(int k , int l , int r , int L , int R , int val)
  {
    if(L <= l && r <= R)
    {
      c[k].maxn += val ;
      c[k].lazy2 += val ;
      return ;
    }
    int mid = l + r >> 1 ;
    push_down(k) ;
    if(L <= mid) update2(lson(k) , l , mid , L , R , val) ;
    if(R > mid) update2(rson(k) , mid + 1 , r , L , R , val) ;
    push_up(k) ;
  }
  int query(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].maxn ;
    }
    int mid = l + r >> 1 ;
    push_down(k) ;
    int maxn = 0 ;
    if(L <= mid) maxn = max(maxn , query(lson(k) , l , mid , L , R)) ;
    if(R > mid) maxn = max(maxn , query(rson(k) , mid + 1 , r , L , R)) ;
    return maxn ;
  }
};
cTr Tr ;
int get(int x , int y)
{
  int maxn = 0 ;
  while(top[x] != top[y])
  {
    while(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    maxn = max(maxn , Tr.query(1 , 1 , n , dfn[top[x]] , dfn[x])) ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  if(x != y)
  {
    maxn = max(maxn , Tr.query(1 , 1 , n , dfn[x] + 1 , dfn[y])) ;
  }
  return maxn ;
}
void change1(int x , int y , int w)
{
  while(top[x] != top[y])
  {
    while(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    Tr.update1(1 , 1 , n , dfn[top[x]] , dfn[x] , w) ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  if(x != y)
  {
    Tr.update1(1 , 1 , n , dfn[x] + 1 , dfn[y] , w) ;
  }
}
void change2(int x , int y , int w)
{
  while(top[x] != top[y])
  {
    while(dep[top[x]] < dep[top[y]]) swap(x , y) ;
    Tr.update2(1 , 1 , n , dfn[top[x]] , dfn[x] , w) ;
    x = Fa[top[x]] ;
  }
  if(dep[x] > dep[y]) swap(x , y) ;
  if(x != y)
  {
    Tr.update2(1 , 1 , n , dfn[x] + 1 , dfn[y] , w) ;
  }
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v , w ;
    cin >> u >> v >> w ;
    G[u].push_back({v , w}) ;
    G[v].push_back({u , w}) ;
    edg[i] = {u , v} ;
  }
  dfs1(1 , 0) ;
  dfs2(1 , 1) ;
  Tr.build(1 , 1 , n) ;
  string s ;
  cin >> s ;
  while(s != "Stop")
  {
    if(s == "Max")
    {
      int u , v ;
      cin >> u >> v ;
      cout << get(u , v) << "\n" ;
    }
    else if(s == "Cover")
    {
      int u , v , w ;
      cin >> u >> v >> w ;
      change1(u , v , w) ;
    }
    else if(s == "Add")
    {
      int u , v , w ;
      cin >> u >> v >> w ;
      change2(u , v , w) ;
    }
    else
    {
      int k , w ;
      cin >> k >> w ;
      int u = edg[k].u , v = edg[k].v ;
      if(dep[u] > dep[v]) swap(u , v) ;
      Tr.update1(1 , 1 , n , dfn[v] , dfn[v] , w) ;
    }
    cin >> s ;
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