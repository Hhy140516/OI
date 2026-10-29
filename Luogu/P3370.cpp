#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 48932573 , base1 = 131 , base2 = 13331 ;
int n ;
bool f1[50000005] , f2[50000005] ;
pair<ll , ll> get(string s)
{
  ll nw1 = 0 , nw2 = 0 ;
  for( int j = 0 ; j < s.size() ; j++ )
  {
    nw1 = nw1 * base1 % MOD + s[j] ;
    nw2 %= MOD ;
    nw2 = nw2 * base2 % MOD + s[j] ;
    nw2 %= MOD ;
  }
  return {nw1 , nw2} ;
}
void solve()
{
  cin >> n ;
  int cnt = n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    string s ;
    cin >> s ;
    pair<int , int> p = get(s) ;
    if(f1[p.first] && f2[p.second]) cnt-- ;
    f1[p.first] = f2[p.second] = 1 ;
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