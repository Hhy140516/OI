#include<bits/stdc++.h>
using namespace std ;
#define int long long
int dp[605][605] ;
int n ;
int s[605] ;
int a[305] ;
void solve()
{
	cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> a[i] ;
    s[i] = s[i - 1] + a[i] ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    s[i + n] = s[i + n - 1] + a[i] ;
  }
  memset(dp , 0x3f , sizeof dp) ;
  for( int i = 1 ; i <= 2 * n ; i++ ) dp[i][i] = 0 ;
  for( int len = 2 ; len <= n ; len++ )
  {
    for( int l = 1 ; l + len - 1 <= 2 * n ; l++ )
    {
      int r = l + len - 1 ;
      for( int mid = l ; mid < r ; mid++ )
      {
        dp[l][r] = min(dp[l][r] , dp[l][mid] + dp[mid + 1][r] + s[r] - s[l - 1]) ;
      }
    }
  }
  int minn = 1e9 ;
  for( int i = 1 ; i <= n + 1 ; i++ ) minn = min(minn , dp[i][i + n - 1]) ;
  cout << minn << "\n" ;
  memset(dp , -0x3f , sizeof dp) ;
  for( int i = 1 ; i <= 2 * n ; i++ ) dp[i][i] = 0 ;
  for( int len = 2 ; len <= n ; len++ )
  {
    for( int l = 1 ; l + len - 1 <= 2 * n ; l++ )
    {
      int r = l + len - 1 ;
      for( int mid = l ; mid < r ; mid++ )
      {
        dp[l][r] = max(dp[l][r] , dp[l][mid] + dp[mid + 1][r] + s[r] - s[l - 1]) ;
      }
    }
  }
  int maxn = 0 ;
  for( int i = 1 ; i <= n + 1 ; i++ ) maxn = max(maxn , dp[i][i + n - 1]) ;
  cout << maxn << "\n" ;
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}