#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int kMaxN = 1e6 + 5 ;
int l , r ;
int n , k ;
int a[kMaxN] ;
int st[kMaxN] ;
void getmin()
{
  l = 1 , r = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    while(l <= r && a[st[r]] > a[i]) r-- ;
    st[++r] = i ;
    while(l <= r && st[l] <= i - k) l++ ;
    if(i >= k)
    {
      cout << a[st[l]] << " " ;
    }
  }
}
void getmax()
{
  l = 1 , r = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    while(l <= r && a[st[r]] < a[i]) r-- ;
    st[++r] = i ;
    while(l <= r && st[l] <= i - k) l++ ;
    if(i >= k)
    {
      cout << a[st[l]] << " " ;
    }
  }
}
void solve()
{
  cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> a[i] ;
  }
  getmin() ;
  cout << "\n" ;
  getmax() ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}