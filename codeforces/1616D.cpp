#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , INF = 0x3f3f3f3f ;
int n , x ;
int a[kMaxN] ;
void solve()
{
	cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  cin >> x ;
  for( int i = 1 ; i <= n ; i++ ) a[i] -= x ;
	int as = n ;
  for( int i = 2 ; i <= n ; i++ )
  {
    if(a[i] + a[i - 1] < 0 || a[i] + a[i - 1] + a[i - 2] < 0)
    {
      as-- ;
      a[i] = INF ;
    }
  }
  cout << as << "\n" ;
}
signed main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
	int oT_To = 1 ;
	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}