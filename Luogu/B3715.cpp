#include<bits/stdc++.h>
using namespace std ;
void solve()
{
  long long n ;
  cin >> n ;
  for( long long i = 2 ; i * i <= n ; i++ )
  {
    while(n % i == 0)
    {
      cout << i << " " ;
      n /= i ;
    }
  }
  if(n != 1) cout << n ;
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