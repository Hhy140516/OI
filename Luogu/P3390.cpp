#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 1e9 + 7 ;
int n ;
ll k ;
struct node
{
  ll a[105][105] ;
  node()
  {
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) a[i][j] = 0 ;
  }
};
node operator * (const node &a , const node &b)
{
  node c ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ )
    {
      for( int k = 1 ; k <= n ; k++ )
      {
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % MOD) % MOD ;
      }
    }
  }
  return c ;
}
node ksm(node a , ll b)
{
  node mul ;
  for( int i = 1 ; i <= n ; i++ ) mul.a[i][i] = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a ;
    a = a * a ;
    b >>= 1 ;
  }
  return mul ;
}
void solve()
{
  cin >> n >> k ;
  node A ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ ) cin >> A.a[i][j] ;
  }
  A = ksm(A , k) ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= n ; j++ ) cout << A.a[i][j] << " " ;
    cout << "\n" ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}