#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 1e9 + 7 ;
int n ;
int val[1000005] ;
vector<int> G[1000005] ;
ll sum ;
void dfs(int u , int fa , int maxn , int step)
{
  if(fa)
  {
    sum = (sum + (maxn - step + MOD) % MOD) % MOD ;
  }
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i] ;
    if(v == fa) continue ;
    dfs(v , u , max(maxn , val[v]) , step + 1) ;
  }
}
void solve()
{ 
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> val[i] ;
  for( int i = 1 ; i < n ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    dfs(i , 0 , val[i] , 0) ;
  }
  cout << sum ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("travel.in" , "r" , stdin) ;
  freopen("travel.out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}