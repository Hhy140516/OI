#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
ll x ;
ll a[kMaxN] ;
bool f[kMaxN] ;
bool check(ll mid)
{
  for( int i = 1 ; i <= n ; i++ ) f[i] = 0 ;
  for( int i = 2 ; i <= n ; i++ )
  {
    if(a[i] - a[i - 1] <= mid) 
    {
      f[i - 1] = f[i] = 1 ;
    }
  }
  ll cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(f[i]) continue ;
    if(i < n && f[i + 1] == 0)
    {
      if(a[i] + mid >= a[i + 1] - mid)
      {
        cnt++ ;
        f[i] = f[i + 1] = 1 ;
      }
      else
      {
        cnt++ ;
        f[i] = 1 ;
      }
    }
    else
    {
      cnt++ ;
      f[i] = 1 ;
    }
  }
  return cnt <= x ;
}
void solve()
{
  cin >> n >> x ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  ll l = 1 , r = 1e12 ;
  while(l < r)
  {
    ll mid = l + r >> 1 ;
    if(check(mid)) r = mid ;
    else l = mid + 1 ;
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