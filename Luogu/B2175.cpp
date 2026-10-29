#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
int a[5005] , b[5005] ;
int dp[5005][5005] ;
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  for( int i = 1 ; i <= m ; i++ ) cin >> b[i] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= m ; j++ )
    {
      dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
      if(a[i] == b[j]) dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1) ;
    }
  }
  cout << dp[n][m] ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}