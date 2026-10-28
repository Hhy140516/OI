#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
string s[3] ;
void solve()
{
  cin >> n ;
  cin >> s[1] >> s[2] ;
  s[1] = ' ' + s[1] ;
  s[2] = ' ' + s[2] ;
  int cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ ) cnt += (s[1][i] == 'f') + (s[2][i] == 'f') ;
  cout << cnt % 2 << "\n" ;
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