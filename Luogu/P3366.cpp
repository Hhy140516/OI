#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n , m ;
struct edge
{
  int u , v , w ;
  bool operator < (const edge &a) const
  {
    return w < a.w ;
  }
}edg[200005] ;
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
  for( int i = 1 ; i <= m ; i++ )
  {
    int u = edg[i].u , v = edg[i].v , w = edg[i].w ;
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
    edg[i] = {u , v , w} ;
  }
  sort(edg + 1 , edg + m + 1) ;
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