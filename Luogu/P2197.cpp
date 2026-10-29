#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve()
{
  int n , X = 0 ;
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x ;
    cin >> x ;
    X ^= x ;
  } 
  if(X != 0) cout << "Yes\n" ;
  else cout << "No\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}