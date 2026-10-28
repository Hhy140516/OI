#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int k , n ;
vector<int> G[kMaxN] ;
void solve()
{
  cin >> k ;
  int root , id = -1 ;
  for( int i = 1 ; i <= k ; i++ )
  {
    cin >> n ;
    for( int j = 1 ; j <= n ; j++ ) G[j].clear() ;
    for( int j = 1 ; j < n ; j++ )
    {
      int u , v ;
      cin >> u >> v ;
      G[u].push_back(v) ;
      G[v].push_back(u) ;
    }
    if(id == -1 && n > 1)
    {
      for( int j = 1 ; j <= n ; j++ )
      {
        if(G[j].size() == 1)
        {
          id = i ;
          root = G[j][0] ;
          break ;
        }
      }
    }
  }
  if(id == -1)
  {
    id = root = 1 ;
  }
  for( int i = 1 ; i <= k ; i++ )
  {
    if(i == id) continue ;
    cout << i << " 1 " << id << " " << root << "\n" ;
  }
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