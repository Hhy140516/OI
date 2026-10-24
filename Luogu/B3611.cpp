#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
bool f[105][105] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ ) cin >> f[i][j] ;
  }
  for( int k = 1 ; k <= n ; k++ )
  {
    for( int i = 1 ; i <= n ; i++ )
    {
      for( int j = 1 ; j <= n ; j++ ) f[i][j] |= (f[i][k] && f[k][j]) ;
    }
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ ) cout << f[i][j] << " " ;
    cout << "\n" ;
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