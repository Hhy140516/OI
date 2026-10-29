#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int n ;
void solve()
{
  cin >> n ;
  ll gcd = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    ll x ;
    cin >> x ;
    gcd = __gcd(gcd , x) ;
  }
  cout << abs(gcd) ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}