#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n , m ;
ll s[5005][5005] ;
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x , y , v ;
    cin >> x >> y >> v ;
    s[x + 1][y + 1] += v ;
  }
  for( int i = 1 ; i <= 5001 ; i++ )
  {
    for( int j = 1 ; j <= 5001 ; j++ )
    {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] ;
    }
  }
  ll maxn = 0 ;
  for( int i = m ; i <= 5001 ; i++ )
  {
    for( int j = m ; j <= 5001 ; j++ )
    {
      maxn = max(maxn , s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]) ;
    }
  }
  cout << maxn ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}