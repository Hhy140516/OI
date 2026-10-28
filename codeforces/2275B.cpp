#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n ;
string s ;
bool f[kMaxN] ;
void solve()
{
  cin >> n >> s ;
  s = ' ' + s ;
  for( int i = 1 ; i <= n ; i++ ) f[i] = 0 ;
  stack<int> st ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(s[i] == '1')
    {
      st.push(i) ;
    }
    else if(s[i] == '2')
    {
      if(st.empty()) f[i] = 1 ;
      else 
      {
        f[st.top()] = 1 ;
        st.pop() ;
      }
    }
    else
    {
      f[i] = 1 ;
    }
  }
  int cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ ) cnt += !f[i] ;
  cout << cnt << "\n" ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(!f[i]) cout << i << " " ;
  }
  cout << "\n" ;
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