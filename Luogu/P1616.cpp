#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int kMaxT = 1e7 + 2 ;
int t , n ;
int dp[kMaxT] ;
void solve()
{
  cin >> t >> n ;
  memset(dp , -0x3f , sizeof dp) ;
  dp[0] = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int T , v ;
    cin >> T >> v ;
    for( int j = 0 ; j <= t ; j++ )
    {
      if(j - T >= 0) dp[j] = max(dp[j - T] + v , dp[j]) ;
    }
  }
  int maxn = 0 ;
  for( int i = 0 ; i <= t ; i++ ) maxn = max(maxn , dp[i]) ;
  cout << maxn ;
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