#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n ;
string s ;
int p[22000105] ;
void solve()
{
  cin >> s ;
  n = s.size() ;
  string S ;
  S += "$" ;
  for( int i = 0 ; i < n ; i++ )
  {
    S += '#' ;
    S += s[i] ;
  }
  n = S.size() ;
  S += "#^" ;
  s = S ;
  int r = 0 , mid = 0 ;
  int maxn = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    p[i] = (i < r ? min(p[2 * mid - i] , r - i) : 1) ;
    while(s[i - p[i]] == s[i + p[i]]) p[i]++ ;
    if(i + p[i] > r)
    {
      r = i + p[i] ;
      mid = i ;
    }
    maxn = max(maxn , p[i] - 1) ;
  }
  cout << maxn ;
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}