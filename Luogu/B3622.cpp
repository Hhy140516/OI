#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 15 ;
int n ;
bool f[kMaxN] ;
void dfs(int step)
{
  if(step > n)
  {
    for( int i = 1 ; i <= n ; i++ ) cout << (f[i] ? 'Y' : 'N') ;
    cout << "\n" ;
    return ;
  }
  f[step] = 0 ;
  dfs(step + 1) ;
  f[step] = 1 ;
  dfs(step + 1) ;
}
void solve()
{
  cin >> n ;
  dfs(1) ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}