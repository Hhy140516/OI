#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
int a[kMaxN] ;
map<ll , ll> mp ;
void solve()
{
  mp.clear() ;
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  ll as = 0 ; 
  for( int i = 1 ; i <= n - 4 ; i++ ) 
  {
    as += mp[a[i] + a[i + 2] - a[i + 4]] ;
    if(i > 2 && a[i - 2] + a[i] - a[i + 2] == a[i] + a[i + 2] - a[i + 4]) as-- ;
    if(i > 4 && a[i - 4] + a[i - 2] - a[i] == a[i] + a[i + 2] - a[i + 4]) as-- ;
    mp[a[i] + a[i + 2] - a[i + 4]]++ ;
  }
  cout << as << "\n" ;
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