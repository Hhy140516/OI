#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e6 + 5 ;
int n , p ;
int d[kMaxN] ;
void solve()
{
  cin >> n >> p ;
  int lst = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x ;
    cin >> x ;
    d[i] = x - lst ;
    lst = x ;
  }
  while(p--)
  {
    int x , y , z ;
    cin >> x >> y >> z ;
    d[x] += z ;
    d[y + 1] -= z ;
  }
  int minn = 2e9 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    d[i] += d[i - 1] ;
    minn = min(minn , d[i]) ;
  }
  cout << minn ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}