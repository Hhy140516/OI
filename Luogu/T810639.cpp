#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll n , k ;
void solve()
{
  cin >> n >> k ;
  ll maxx = (n + 2) / 2 ;
  if(k >= maxx)
  {
    cout << 2 * n - k << "\n" ;
  }
  else
  {
    if(n % 2 == 0 && k == n / 2) cout << 3 * k - 1 << "\n" ;
    else cout << 3 * k << "\n" ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}