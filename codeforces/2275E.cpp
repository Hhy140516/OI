#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
int a[kMaxN] , b[kMaxN] ;
ll s[kMaxN] , t[kMaxN] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  for( int i = 1 ; i <= n ; i++ ) cin >> b[i] ;
  s[n] = t[n] = 0 ;
  for( int i = n - 1 ; i >= 1 ; i-- )
  {
    s[i] = t[i + 1] + 1 + (a[i] == b[i + 1]) ;
    t[i] = s[i + 1] + 1 + (b[i] == a[i + 1]) ;
  }
  ll ans = s[1] + t[1] + 1 + (a[n] == b[n]) ;
  ll sum = 0 ;
  for( int i = 1 ; i < n ; i++ )
  {
    ans = max(ans , max(sum + t[i] + t[i + 1] + 2 + (a[i] == b[i]) + (a[n] == b[n]) , sum + s[i] + t[i] + 1 + (a[n] == b[n]))) ;
    sum += 2 + (a[i] == b[i]) + (b[i] == a[i + 1]) ;
  }
  cout << ans << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}