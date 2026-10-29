#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll a , b  , c ;
ll ksm(ll a , ll b , ll c)
{
  ll mul = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a % c ;
    a = a * a % c ;
    b >>= 1 ;
  }
  return mul ;
}
void solve()
{
  cin >> a >> b >> c ;
  cout << a << '^' << b << " mod " << c << '=' << ksm(a , b , c) ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}