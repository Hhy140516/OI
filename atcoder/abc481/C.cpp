#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ; 
int q ;
map<string  , int> mp ;
int tot = 0 ;
void solve()
{
  cin >> q ;
  while(q--)
  {
    string s ;
    cin >> s ;
    if(mp[s] == 0)
    {
      mp[s] = ++tot ;
    }
    cout << mp[s] << "\n" ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}