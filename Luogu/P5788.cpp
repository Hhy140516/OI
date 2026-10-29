#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
int a[3000005] ;
int stk[3000005] , top , ans[3000005] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  for( int i = n ; i >= 1 ; i-- )
  {
    while(top && a[stk[top]] <= a[i]) top-- ;
    ans[i] = stk[top] ;
    stk[++top] = i ;
  }
  for( int i = 1 ; i <= n ; i++ ) cout << ans[i] << " " ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}