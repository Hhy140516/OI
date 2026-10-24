#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ; 
int a , b ;
bool f[10] ;
void solve()
{
  cin >> a >> b ;
  int c = a + b ;
  int cnt = 0 ;
  while(c)
  {
    cnt++ ;
    c /= 10 ;
  }
  cout << cnt ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}