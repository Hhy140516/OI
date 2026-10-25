#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int a , b , c , d ;
int get(int na , int nb , int nc , int nd)
{
  int o = 0 ; 
  if(na < a) o = max(o , (a - na) * 4) ;
  if(nb < b) o = max(o , (b - nb) * 2) ;
  if(nc < c) o = max(o , (c - nc) * 2) ;
  if(nd < d) o = max(o , (d - nd)) ;
  return o ;
}
void solve()
{
  cin >> a >> b >> c >> d ;
  int maxn = max({a , b , c , d}) * 4 ;
  int as = 1e9 ;
  for( int i = 0 ; i <= maxn ; i++ )
  {
    for( int j = 0 ; j <= maxn ; j++ )
    {
      int na = i + j / 2 , nb = i / 2 + j , nc = i / 2 + j / 4 , nd = i / 4 + j / 2 ;
      int l = 0 , r = maxn ;
      while(r - l >= 10)
      {
        int mid1 = (2 * l + r) / 3 , mid2 = (l + 2 * r) / 3 ;
        if(mid1 + get(na + mid1 / 2 , nb + mid1 / 4 , nc + mid1 , nd + mid1 / 2) < mid2 + get(na + mid2 / 2 , nb + mid2 / 4 , nc + mid2 , nd + mid2 / 2)) r = mid2 ;
        else l = mid1 ;
      }
      for( int k = l ; k <= r ; k++ )
      {
        int o = get(na + k / 2 , nb + k / 4 , nc + k , nd + k / 2) ;
        as = min(as , i + j + k + o) ;
      }
    }
  }
  cout << as ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("light.in" , "r" , stdin) ;
  freopen("light.out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}