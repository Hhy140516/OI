#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ;
const long double PI = acosl(-1.0L) , eps = 1e-100L ; 
int n ;
long double d[400005] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    int x , y ;
    cin >> x >> y ;
    d[i] = atan2l(y , x) ;
    if(d[i] < 0) d[i] += 2 * PI ;
  }
  sort(d + 1 , d + n + 1) ;
  for( int i = 1 ; i <= n ; i++ ) d[i + n] = d[i] + 2 * PI ;
  int as = 0 , l = 0 , r = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    l = i ;
    r = max(l , r) ;
    while(r < l + n && d[r] - d[l] < PI - eps) r++ ;
    as = max(as , r - l) ;
  }
  cout << as << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}