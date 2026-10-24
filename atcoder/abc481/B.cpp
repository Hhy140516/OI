#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ; 
int n , k ;
int a[105] ;
void solve()
{
  cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  int as = 0 ;
  for( int i = 1 ; i < n ; i++ )
  {
    int Min = min(a[i] , a[i + 1]) ;
    int Max = max(a[i] , a[i + 1]) ;
    if(Min <= k && k <= Max)
    {
      as++ ;
    }
  }
  for( int i = 2 ; i < n ; i++ )
  {
    if(a[i] == k && a[i - 1] != k && a[i + 1] != k)
    {
      as-- ;
    }
  }
  cout << as ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}