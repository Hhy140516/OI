#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxL = 2e7 , base1 = 13331 , base2 = 131 , MOD1 = 1e7 + 1 , MOD2 = 1e7 + 3 ;
int n ;
bool vis1[kMaxL] , vis2[kMaxL] ;
void solve()
{
  cin >> n ;
  int cnt = n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    string s ;
    cin >> s ;
    long long nw1 = 0 , nw2 = 0 ;
    for( int j = 0 ; j < s.size() ; j++ )
    {
      nw1 = nw1 * base1 % MOD1 + s[j] ;
      nw2 %= MOD1 ;
      nw2 = nw2 * base2 % MOD2 + s[j] ;
      nw2 %= MOD2 ;
    }
    if(vis1[nw1] && vis2[nw2]) cnt-- ;
    vis1[nw1] = vis2[nw2] = 1 ;
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