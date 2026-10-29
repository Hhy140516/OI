#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , INF = 1e9 ;
int n , q ;
struct node
{
  int v , w ;
};
vector<node> G[kMaxN] ;
int Fa[kMaxN] , dep[kMaxN] , siz[kMaxN] , son[kMaxN] , a[kMaxN] ;
int top[kMaxN] , dfn[kMaxN] , id[kMaxN] , tot ;
void dfs1(int u , int fa)
{
  Fa[u] = fa ;
  dep[u] = dep[fa] + 1 ;
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
    int maxn , minn , sum ;
    bool lazy ;
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
    c[k].maxn = max(c[lson(k)].maxn , c[rson(k)].maxn) ;
    c[k].minn = min(c[lson(k)].minn , c[rson(k)].minn) ;
    c[k].sum = c[lson(k)].sum + c[rson(k)].sum ;
  }
  void push_down(int k)
  {
    if(c[k].lazy)
    {
      node son1 = c[lson(k)] ;
      node son2 = c[rson(k)] ;
      c[lson(k)].maxn = -son1.minn ;
      c[lson(k)].minn = -son1.maxn ;
      c[lson(k)].sum = -son1.sum ;
      c[lson(k)].lazy ^= 1 ;
      c[rson(k)].maxn = -son2.minn ;
      c[rson(k)].minn = -son2.maxn ;
      c[rson(k)].sum = -son2.sum ;
      c[rson(k)].lazy ^= 1 ;
      c[k].lazy = 0 ;
    }
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].maxn = c[k].minn = c[k].sum = a[id[l]] ;
      return ;
    }
    int mid = l + r >> 1 ;
    build(lson(k) , l , mid) ;
    build(rson(k) , mid + 1 , r) ;
    push_up(k) ;
  }
  void update1(int k , int l , int r , int id , int val)
  {
    if(l == r)
    {
      c[k].maxn = c[k].minn = c[k].sum = val ;
      return ;
    }
    int mid = l + r >> 1 ;
    push_down(k) ;
    if(id <= mid) update1(lson(k) , l , mid , id , val) ;
    else update1(rson(k) , mid + 1 , r , id , val) ;
    push_up(k) ;
  }
  void update2(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      c[k].lazy ^= 1 ;
      node u = c[k] ;
      c[k].maxn = -u.minn ;
      c[k].minn = -u.maxn ;
      c[k].sum = -u.sum ;
      return ;
    }
    int mid = l + r >> 1 ;
    push_down(k) ;
    if(L <= mid) update2(lson(k) , l , mid , L , R) ;
    if(R > mid) update2(rson(k) , mid + 1 , r , L , R) ;
    push_up(k) ;
  }
  int query1(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].sum ;
    }
    int mid = l + r >> 1 ;
    int sum = 0 ;
    push_down(k) ;
    if(L <= mid) sum += query1(lson(k) , l , mid , L , R) ;
    if(R > mid) sum += query1(rson(k) , mid + 1 , r , L , R) ;
    return sum ;
  }
  int query2(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].maxn ;
    }
    int mid = l + r >> 1 ;
    int maxn = -INF ;
    push_down(k) ;
    if(L <= mid) maxn = max(maxn , query2(lson(k) , l , mid , L , R)) ;
    if(R > mid) maxn = max(maxn , query2(rson(k) , mid + 1 , r , L , R)) ;
    return maxn ;
  }
  int query3(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].minn ;
    }
    int mid = l + r >> 1 ;
    int minn = INF ;
    push_down(k) ;
    if(L <= mid) minn = min(minn , query3(lson(k) , l , mid , L , R)) ;
    if(R > mid) minn = min(minn , query3(rson(k) , mid + 1 , r , L , R)) ;
    return minn ;
  }
};
struct edge
{
  int u , v ;
}edg[kMaxN] ;
cTr Tr ;
void change(int u , int v)
{
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    Tr.update2(1 , 1 , n , dfn[top[u]] , dfn[u]) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  Tr.update2(1 , 1 , n , dfn[u] + 1 , dfn[v]) ;
}
int get1(int u , int v)
{
  int sum = 0 ;
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    sum += Tr.query1(1 , 1 , n , dfn[top[u]] , dfn[u]) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  sum += Tr.query1(1 , 1 , n , dfn[u] + 1 , dfn[v]) ;
  return sum ;
}
int get2(int u , int v)
{
  int maxn = -INF ;
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    maxn = max(maxn , Tr.query2(1 , 1 , n , dfn[top[u]] , dfn[u])) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  maxn = max(maxn , Tr.query2(1 , 1 , n , dfn[u] + 1 , dfn[v])) ;
  return maxn ;
}
int get3(int u , int v)
{
  int minn = INF ;
  while(top[u] != top[v])
  {
    if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
    minn = min(minn , Tr.query3(1 , 1 , n , dfn[top[u]] , dfn[u])) ;
    u = Fa[top[u]] ;
  }
  if(dep[u] > dep[v]) swap(u , v) ;
  minn = min(minn , Tr.query3(1 , 1 , n , dfn[u] + 1 , dfn[v])) ;
  return minn ;
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v , w ;
    cin >> u >> v >> w ;
    u++ , v++ ;
    G[u].push_back({v , w}) ;
    G[v].push_back({u , w}) ;
    edg[i] = {u  , v} ;
  }
  dfs1(1 , 0) ;
  dfs2(1 , 1) ;
  Tr.build(1 , 1 , n) ;
  cin >> q ;
  while(q--)
  {
    string s ;
    cin >> s ;
    if(s == "C")
    {
      int id , w ;
      cin >> id >> w ;
      int u = edg[id].u , v = edg[id].v ;
      if(dep[u] > dep[v]) swap(u , v) ;
      Tr.update1(1 , 1 , n , dfn[v] , w) ;
    }
    else if(s == "N")
    {
      int u , v ;
      cin >> u >> v ;
      u++ , v++ ;
      change(u , v) ;
    }
    else if(s == "SUM")
    {
      int u , v ;
      cin >> u >> v ;
      u++ , v++ ;
      cout << get1(u , v) << "\n" ;
    }
    else if(s == "MAX")
    {
      int u , v ;
      cin >> u >> v ;
      u++ , v++ ;
      cout << get2(u , v) << "\n" ;
    }
    else
    {
      int u , v ;
      cin >> u >> v ;
      u++ , v++ ;
      cout << get3(u , v) << "\n" ;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) ,  cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}