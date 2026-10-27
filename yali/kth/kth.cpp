#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e6 + 5 , kMaxK = 505 ;
ll n ;
ll k ;
string s ;
unordered_map<string , ll> mp ;
char q[kMaxN] ;
ll l , r ;
void solve()
{
  cin >> n >> k ;
  cin >> s ;
  s = ' ' + s ;
  mp.clear() ;
  l = 1 , r = 0 ;
  ll len = (k - k % n) / n , ge = k % n ;
  for( ll i = 1 ; i <= len ; i++ )
  {
    for( ll j = 1 ; j <= n ; j++ )
    {
      if(r - l + 1 == 0 || q[l] != s[j]) q[++r] = s[j] ;
      else l++ ;
    }
    string S = "" ;
    for( ll j = l ; j <= r ; j++ )
    {
      S += q[j] ;
    }
    if(mp.count(S))
    {
      ll jie = i - mp[S] ;
      ge += ((len - i) % jie) * n ;
      break ;
    }
    mp[S] = i ;
  }
  for( ll j = 1 ; j <= ge ; j++ )
  {
    if(r - l + 1 == 0 || q[l] != s[(j - 1) % n + 1]) q[++r] = s[(j - 1) % n + 1] ;
    else l++ ;
  }
  cout << r - l + 1 << "\n" ;
  if(r - l + 1 > 0)
  {
    for( ll j = l ; j <= r ; j++ ) cout << q[j] ;
    cout << "\n" ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("repeatqueue.in" , "r" , stdin) ;
  freopen("repeatqueue.out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}

