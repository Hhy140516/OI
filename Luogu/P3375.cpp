#include<bits/stdc++.h>
using namespace std ;
#define int long long
string s , t ;
int nxt[1000005] ;
void init()
{
  nxt[0] = -1 ;
  int i = 0 , j = -1 ;
  while(i < t.size())
  {
    if(j == -1 || t[i] == t[j])
    {
      i++ , j++ ;
      nxt[i] = j ;
    }
    else j = nxt[j] ;
  }
}
void KMP()
{
  int i = 0 , j = 0 ;
  while(i < s.size())
  {
    if(j == t.size() - 1 && s[i] == t[j])
    {
      cout << i - t.size() + 2 << "\n" ;
      j = nxt[j] ;
    }
    if(j == -1 || s[i] == t[j])
    {
      i++ , j++ ;
    }
    else j = nxt[j] ;
  }
}
void solve()
{
  cin >> s >> t ;
  init() ;
  KMP() ;
  for( int i = 0 ; i < t.size() ; i++ ) cout << nxt[i + 1] << " " ;
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}