#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n , k ;
int p[10] ;
void dfs(int step)
{
  if(step > n)
  {
    for( int i = 1 ; i <= n ; i++ ) cout << p[i] << " " ;
    cout << "\n" ;
    return ;
  }
  for( int i = 1 ; i <= k ; i++ )
  {
    p[step] = i ;
    dfs(step + 1) ;
  }
}
void solve()
{
  cin >> n >> k ;
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