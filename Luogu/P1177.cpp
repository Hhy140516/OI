#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int a[kMaxN] , n ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  sort(a + 1 , a + n + 1) ;
  for( int i = 1 ; i <= n ; i++ ) cout << a[i] << " " ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ; 
}