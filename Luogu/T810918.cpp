#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ; 
int n , a[400005] ;
ll fac[400005] , inv[400005] ;
ll ksm(ll a , int b = MOD - 2)
{
  ll mul = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a % MOD ;
    a = a * a % MOD ;
    b >>= 1 ;
  }
  return mul ;
}
void init()
{
  fac[0] = 1 ;
  for( int i = 1 ; i <= 400000 ; i++ ) fac[i] = fac[i - 1] * i % MOD ;
  inv[400000] = ksm(fac[400000]) ;
  for( int i = 400000 ; i >= 1 ; i-- ) inv[i - 1] = inv[i] * i % MOD ;
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= 2 * n ; i++ ) cin >> a[i] ;
  sort(a + 1 , a + 2 * n + 1) ;
  ll as = (a[n + 1] - a[n]) % MOD ;
  as = as * fac[n] % MOD * fac[n] % MOD ;
  as = as * ksm(2 , n) % MOD ;
  cout << as << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  init() ;
  while(oT_To--) solve() ;
  return 0 ;
}