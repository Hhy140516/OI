#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int n , q ;
int w[kMaxN] ;
vector<int> G[kMaxN] ;
int Fa[kMaxN] , dep[kMaxN] , siz[kMaxN] , son[kMaxN] ;
int top[kMaxN] , tot , dfn[kMaxN] , id[kMaxN] ;
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
    int pre , nxt ;
    int cnt , lazy ;
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 2) ; 
  }
  node merge(const node &a , const node &b)
  {
    node c ;
    c.cnt = a.cnt + b.cnt ;
    c.pre = a.pre ;
    c.nxt = b.nxt ;
    c.cnt -= (a.nxt == b.pre) ;
    return c ;
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
    c[k] = merge(c[lson(k)] , c[rson(k)]) ;
  }
  void push_down(int k)
  {
    if(c[k].lazy)
    {
      c[lson(k)].cnt = 1 ;
      c[lson(k)].pre = c[lson(k)].nxt = c[k].lazy ;
      c[lson(k)].lazy = c[k].lazy ;
      c[rson(k)].cnt = 1 ;
      c[rson(k)].pre = c[rson(k)].nxt = c[k].lazy ;
      c[rson(k)].lazy = c[k].lazy ;
      c[k].lazy = 0 ;
    }
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].cnt = 1 ;
      c[k].pre = c[k].nxt = w[id[l]] ;
      return ;
    }
    int mid = l + r >> 1 ;
    build(lson(k) , l , mid) ;
    build(rson(k) , mid + 1 , r) ;
    push_up(k) ;
  }
  void update(int k , int l , int r , int L , int R , int v)
  {
    if(L <= l && r <= R)
    {
      c[k].cnt = 1 ;
      c[k].pre = c[k].nxt = v ;
      c[k].lazy = v ;
      return ;
    }
    push_down(k) ;
    int mid = l + r >> 1 ;
    if(L <= mid) update(lson(k) , l , mid , L , R , v) ;
    if(R > mid) update(rson(k) , mid + 1 , r , L , R , v) ;
    push_up(k) ;
  }
  node query(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k] ;
    }
    push_down(k) ;
    int mid = l + r >> 1 ;
    bool fl = 0 ;
    node as ;
    if(L <= mid)
    {
      if(!fl) as = query(lson(k) , l , mid , L , R) ;
      else as = merge(as , query(lson(k) , l , mid , L , R)) ;
      fl = 1 ;
    }
    if(R > mid)
    {
      if(!fl) as = query(rson(k) , mid + 1 , r , L , R) ;
      else as = merge(as , query(rson(k) , mid + 1 , r , L , R)) ;
      fl = 1 ;
    }
    return as ;
  }
  void change(int u , int v , int c)
  {
    while(top[u] != top[v])
    {
      if(dep[top[u]] < dep[top[v]]) swap(u , v) ;
      update(1 , 1 , n , dfn[top[u]] , dfn[u] , c) ;
      u = Fa[top[u]] ;
    }
    if(dep[u] > dep[v]) swap(u , v) ;
    update(1 , 1 , n , dfn[u] , dfn[v] , c) ;
  }
  int get(int u , int v)
  {
    node as1 , as2 ;
    bool fl1 = 0 , fl2 = 0 ;
    while(top[u] != top[v])
    {
      if(dep[top[u]] >= dep[top[v]]) 
      {
        if(!fl1) as1 = query(1 , 1 , n , dfn[top[u]] , dfn[u]) ;
        else as1 = merge(as1 , query(1 , 1 , n , dfn[top[u]] , dfn[u])) ;
        fl1 = 1 ;
        u = Fa[top[u]] ;
      }
      else
      {
        if(!fl2) as2 = query(1 , 1 , n , dfn[top[v]] , dfn[v]) ;
        else as2 = merge(query(1 , 1 , n , dfn[top[v]] , dfn[v]) , as2) ;
        fl2 = 1 ;
        v = Fa[top[v]] ;
      }
    }
    if(dep[u] > dep[v]) swap(u , v) ;
    if(!fl1) as1 = query(1 , 1 , n , dfn[u] , dfn[v]) ;
    else as1 = merge(as1 , query(1 , 1 , n , dfn[u] , dfn[v])) ;
    fl1 = 1 ;
    if(fl2) as1 = merge(as1 , as2) ;
    return as1.cnt ;
  }
};
cTr Tr ;
void solve()
{
  cin >> n >> q ;
  for( int i = 1 ; i <= n ; i++ ) cin >> w[i] ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  dfs1(1 , 0) ;
  dfs2(1 , 1) ;
  Tr.build(1 , 1 , n) ;
  while(q--)
  {
    char c ;
    cin >> c ;
    if(c == 'C')
    {
      int a , b , c ;
      cin >> a >> b >> c ;
      Tr.change(a , b , c) ;
    }
    else
    {
      int a , b ;
      cin >> a >> b ;
      cout << Tr.get(a , b) << "\n" ;
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