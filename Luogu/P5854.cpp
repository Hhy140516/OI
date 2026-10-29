#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
int a[10000005] ;
int stk[10000005] , top ;
int ls[10000005] , rs[10000005] ;
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int lst = 0 ;
    while(top && a[stk[top]] > a[i])
    {
      lst = stk[top--] ;
    }
    if(top)
    {
      rs[stk[top]] = i ;
    }
    ls[i] = lst ;
    stk[++top] = i ;
  }
  ll L = 0 , R = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    L ^= 1ll * i * (ls[i] + 1) ;
    R ^= 1ll * i * (rs[i] + 1) ;
  }
  cout << L << " " << R ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}