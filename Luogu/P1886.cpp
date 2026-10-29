#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n , k ;
int a[1000005] ;
int st[1000005] , l , r ;
void get_min()
{
  l = 1 , r = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    while(l <= r && a[st[r]] > a[i]) r-- ;
    st[++r] = i ;
    while(l <= r && st[l] <= i - k) l++ ;
    if(i >= k) cout << a[st[l]] << " " ;
  }
}
void get_max()
{
  l = 1 , r = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    while(l <= r && a[st[r]] < a[i]) r-- ;
    st[++r] = i ;
    while(l <= r && st[l] <= i - k) l++ ;
    if(i >= k) cout << a[st[l]] << " " ;
  }
}
void solve()
{
  cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  get_min() ;
  cout << "\n" ;
  get_max() ;
  cout << "\n" ;
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}