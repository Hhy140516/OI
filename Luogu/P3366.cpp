#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
struct edge
{
  int u , v , w ;
  bool operator < (const edge &a) const
  {
    return w < a.w ;
  }
};
vector<edge> ve ;
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
    if(x == fa[x]) return x ;
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
void kru()
{
  dsu D ;
  ll as = 0 ;
  for( int i = 0 ; i < m ; i++ )
  {
    int u = ve[i].u , v = ve[i].v , w = ve[i].w ;
    if(!D.check(u , v))
    {
      D.unionn(u , v) ;
      as += w ;
    }
  }
  for( int i = 2 ; i <= n ; i++ )
  {
    if(!D.check(1 , i))
    {
      cout << "orz" ;
      return ;
    }
  }
  cout << as ;
}
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= m ; i++ )
  {
    int u , v , w ;
    cin >> u >> v >> w ;
    ve.push_back({u , v , w}) ;
  }
  sort(ve.begin() , ve.end()) ;
  kru() ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}