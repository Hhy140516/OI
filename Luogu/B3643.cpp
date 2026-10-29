#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int kMaxN = 1e3 + 5 ;
int n , m ;
int g[kMaxN][kMaxN] ;
int a[kMaxN][kMaxN] ;
int c[kMaxN] ;
void solve()
{
	int n , m ;
	cin >> n >> m ;
	for( int i = 1 ; i <= m ; i++ )
	{
		int x , y ;
		cin >> x >> y ;
		g[x][y] = 1 ;
		g[y][x] = 1 ;
		c[x]++ ;
		c[y]++ ;
		a[x][c[x]] = y ;
		a[y][c[y]] = x ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= n ; j++ )
		{
			cout << g[i][j] << " " ;
		}
		cout << "\n" ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		sort(a[i] + 1 , a[i] + c[i] + 1) ;
		cout << c[i] << " " ;
		for( int j = 1 ; j <= c[i] ; j++ )
		{
			cout << a[i][j] << " " ;
		}
		cout << "\n" ;
	}
} 
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}