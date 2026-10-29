#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int k ;
ll c[2005][2005] ;
ll s[2005][2005] ;
void init()
{
  c[0][0] = c[1][0] = c[1][1] = 1 ;
  for( int i = 2 ; i <= 2000 ; i++ )
  {
    c[i][0] = 1 ;
    for( int j = 1 ; j <= i ; j++ )
    {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k ;
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] ;
      if(c[i][j] == 0) s[i][j]++ ;
    }
    s[i][i + 1] = s[i][i] ;
  }
}
int n , m ;
void solve()
{
  cin >> n >> m ;
  if(m > n) cout << s[n][n] << "\n" ;
  else cout << s[n][m] << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To >> k ;
  init() ;
  while(oT_To--) solve() ;
  return 0 ;
}