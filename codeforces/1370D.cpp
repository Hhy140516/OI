#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n , k ;
int a[kMaxN] ;
bool check(int mid , int cur)
{
  int cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(cur)
    {
      cnt++ ;
      cur ^= 1 ;
    }
    else
    {
      if(a[i] <= mid) 
      {
        cnt++ ;
        cur ^= 1 ;
      }
    }
  }
  return cnt >= k ;
}
void solve()
{
	cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
	int l = 0 , r = 1e9 ;
  while(l < r)
  {
    int mid = l + r >> 1 ;
    if(check(mid , 0) || check(mid , 1)) r = mid ;
    else l = mid + 1 ;
  }
  cout << l ;
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