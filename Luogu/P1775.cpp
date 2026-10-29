#include<bits/stdc++.h>
using namespace std ;
#define int long long
int dp[305][305] ;
int n ;
int s[305] ;
void solve()
{
	cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x ;
    cin >> x ;
    s[i] = s[i - 1] + x ;
  }
  memset(dp , 0x3f , sizeof dp) ;
  for( int i = 1 ; i <= n ; i++ ) dp[i][i] = 0 ;
  for( int len = 2 ; len <= n ; len++ )
  {
    for( int l = 1 ; l + len - 1 <= n ; l++ )
    {
      int r = l + len - 1 ;
      for( int mid = l ; mid < r ; mid++ )
      {
        dp[l][r] = min(dp[l][r] , dp[l][mid] + dp[mid + 1][r] + s[r] - s[l - 1]) ;
      }
    }
  }
  cout << dp[1][n] ;
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