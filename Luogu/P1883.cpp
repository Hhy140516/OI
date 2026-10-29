#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const ll kMaxN = 1e4 + 5 ;
const double eps = 1e-9 ;
int n ;
double a[kMaxN] , b[kMaxN] , c[kMaxN] ;
double f(double x)
{
  double maxn = -1e18 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    maxn = max(maxn , a[i] * x * x + b[i] * x + c[i]) ;
  }
  return maxn ;
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] >> b[i] >> c[i] ;
  double l = 0 , r = 1000 ;
  while(r - l >= eps)
  {
    double mid1 = (2 * l + r) / 3 ;
    double mid2 = (l + 2 * r) / 3 ;
    if(f(mid1) < f(mid2)) r = mid2 ;
    else l = mid1 ;
  }
  cout << fixed << setprecision(4) << f(l) << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}