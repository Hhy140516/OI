#include<bits/stdc++.h>
using namespace std ;
int n ;
int a[100005] , b[100005] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    cin >> a[i] ;
    b[i] = a[i] ;
  }
  sort(b + 1 , b + n + 1) ;
  int N = unique(b + 1 , b + n + 1) - (b + 1) ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cout << lower_bound(b + 1 , b + N + 1 , a[i]) - b << " " ;
  }
  cout << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}