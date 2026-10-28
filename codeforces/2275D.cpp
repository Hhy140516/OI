#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
ll k ;
ll a[kMaxN] , b[kMaxN] , c[kMaxN] ;
bool check(ll mid)
{
  ll cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(a[i] + b[i] + c[i] >= mid) continue ;
    if(a[i] > b[i] || b[i] > c[i] || a[i] > c[i])
    {
      cnt += mid - (a[i] + b[i] + c[i]) ;
    }
    else
    {
      if(a[i] == c[i])
      {
        return 0 ;
      }
      else
      {
        ll minn = 3e18 ;
        // b[i] 变小
        ll nw1 = b[i] - a[i] + 1 ;
        minn = min(minn , nw1 + mid - (a[i] + a[i] - 1 + c[i])) ;
        // a[i] 变小
        if(a[i] < b[i])
        {
          ll nw2 = c[i] - b[i] + 1 ;
          minn = min(minn , nw2 + mid - (a[i] + b[i] + b[i] - 1)) ;
        }
        cnt += minn ;
      }
    }
    if(cnt > k) return 0 ;
  }
  return cnt <= k ;
}
void solve()
{
  cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] >> b[i] >> c[i] ;
  ll l = -3e18 , r = 3e18 ;
  while(l < r)
  {
    ll mid = (l + r + 1) / 2 ;
    if(check(mid)) l = mid ;
    else r = mid - 1 ;
  }
  cout << l << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}