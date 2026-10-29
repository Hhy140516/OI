#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , q ;
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
    if(y != x) fa[y] = x ;
  }
  bool check(int x , int y)
  {
    return find(x) == find(y) ;
  }
};
void solve()
{
  cin >> n >> q ;
  dsu D ;
  while(q--)
  {
    int opt ;
    cin >> opt ;
    if(opt == 1)
    {
      int x , y ;
      cin >> x >> y ;
      D.unionn(x , y) ;
    }
    else
    {
      int x , y ;
      cin >> x >> y ;
      if(D.check(x , y)) cout << "Y\n" ;
      else cout << "N\n" ;
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