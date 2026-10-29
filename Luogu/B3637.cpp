#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
int dp[5005] ;
int a[5005] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> a[i] ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		int maxn = 0 ;
		for( int j = 1 ; j < i ; j++ )
		{
			if(a[j] < a[i]) maxn = max(maxn , dp[j]) ;
		}
		dp[i] = maxn + 1 ;
	}
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i++ )
	{
		ans = max(ans , dp[i]) ;
	}
	cout << ans ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}
