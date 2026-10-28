#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 , kMaxM = 2e5 + 5 ;
int n , m , q ;
struct edge
{
  int u , v , w ;
  bool operator < (const edge &a) const
  {
    return w < a.w ;
  }
}edg[kMaxM] ;
ll sum[kMaxN] ;
struct dsu
{
  vector<int> fa ;
  dsu()
  {
    fa.resize(n + 2) ;
    for( int i = 1 ; i <= n ; i++ ) fa[i] = i ;
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
    if(x != y) fa[y] = x ;
  }
  bool check(int x , int y)
  {
    return find(x) == find(y) ;
  }
};
void solve()
{
  cin >> n >> m >> q ;
  ll as = 0 ;
  for( int i = 1 ; i <= m ; i++ )
  {
    int u , v , w ;
    cin >> u >> v >> w ;
    edg[i] = {u , v , w} ;
    as += w ;
  }
  sort(edg + 1 , edg + m + 1) ;
  int res = n ;
  dsu D ;
  vector<int> ve ;
  for( int i = 1 ; i <= m ; i++ )
  {
    int u = edg[i].u , v = edg[i].v , w = edg[i].w ;
    if(!D.check(u , v))
    {
      D.unionn(u , v) ;
      res-- ;
      as -= w ;
      ve.push_back(w) ;
    }
  }
  sort(ve.begin() , ve.end() , greater<int>()) ;
  for( int i = 0 ; i < ve.size() ; i++ ) sum[i + 1] = sum[i] + ve[i] ;
  while(q--)
  {
    ll x ;
    cin >> x ;
    int l = 0 , r = ve.size() ;
    while(l < r)
    {
      int mid = l + r >> 1 ;
      if(mid < ve.size() && 1ll * ve[mid] > 1ll * (mid + res) * x) l = mid + 1 ;
      else r = mid ;
    }
    int k = l ;
    cout << as + sum[k] - 1ll * (res + k - 1) * (res + k) * x / 2 << " " ;
  }
  cout << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}