#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e4 + 5 ;
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
    int maxn , minn ;
    int val , rval ;
    int lazy ;
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 2) ; 
  }
  friend node operator + (const node &a , const node &b)
  {
    node c ;
    c.lazy = 0 ;
    c.val = max(max(a.val , b.val) , b.maxn - a.minn) ; 
    c.rval = max(max(a.rval , b.rval) , a.maxn - b.minn) ;
    c.maxn = max(a.maxn , b.maxn) ;
    c.minn = min(a.minn , b.minn) ;
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
    c[k] = c[lson(k)] + c[rson(k)] ;
  }
  void push_down(int k)
  {
    if(c[k].lazy)
    {
      c[lson(k)].maxn += c[k].lazy ;
      c[lson(k)].minn += c[k].lazy ;
      c[lson(k)].lazy += c[k].lazy ;
      c[rson(k)].maxn += c[k].lazy ;
      c[rson(k)].minn += c[k].lazy ;
      c[rson(k)].lazy += c[k].lazy ;
      c[k].lazy = 0 ;
    }
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].maxn = c[k].minn = w[id[l]] ;
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
      c[k].maxn += v ;
      c[k].minn += v ;
      c[k].lazy += v ;
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
      else as = as + query(lson(k) , l , mid , L , R) ;
      fl = 1 ;
    }
    if(R > mid)
    {
      if(!fl) as = query(rson(k) , mid + 1 , r , L , R) ;
      else as = as + query(rson(k) , mid + 1 , r , L , R) ;
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
				node C = query(1 , 1 , n , dfn[top[u]] , dfn[u]) ;
				swap(C.val , C.rval) ;
				if(!fl1) as1 = C ;
				else as1 = as1 + C ;
				fl1 = 1 ;
				u = Fa[top[u]] ;
			}
			else
			{
				node C = query(1 , 1 , n , dfn[top[v]] , dfn[v]) ;
				if(!fl2) as2 = C ;
				else as2 = C + as2 ;
				fl2 = 1 ;
				v = Fa[top[v]] ;
			}
		}
		if(dep[u] < dep[v]) 
		{
			node C = query(1 , 1 , n , dfn[u] , dfn[v]) ;
			if(!fl2) as2 = C ;
			else as2 = C + as2 ;
			fl2 = 1 ;
		}
		else if(dep[u] > dep[v])
		{
			node C = query(1 , 1 , n , dfn[v] , dfn[u]) ;
			swap(C.val , C.rval) ;
			if(!fl1) as1 = C ;
			else as1 = as1 + C ;
			fl1 = 1 ;
		}
		else
    {
      node C = query(1 , 1 , n , dfn[u] , dfn[u]) ;
      if(!fl1) as1 = C ;
      else as1 = as1 + C ;
      fl1 = 1 ;
    }
		if(fl1 && fl2) return (as1 + as2).val ;
		else if(fl1) return as1.val ;
		else if(fl2) return as2.val ;
		return 0 ;
  }
};
cTr Tr ;
void solve()
{
  cin >> n ;
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
  cin >> q ;
  while(q--)
  {
    int a , b , c ;
    cin >> a >> b >> c ;
    cout << Tr.get(a , b) << "\n" ;
    Tr.change(a , b , c) ;
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
