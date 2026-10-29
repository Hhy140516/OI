#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 105 ;
int n , m ;
char c[kMaxN][kMaxN] ;
bool vis[kMaxN][kMaxN] ;
int cx[] = {0 , 0 , 1 , -1} , cy[] = {1 , -1 , 0 , 0} ;
void bfs()
{
  queue<pair<int , int> > q ;
  vis[1][1] = 1 ;
  q.push({1 , 1}) ;
  while(!q.empty())
  {
    pair<int , int> u = q.front() ;
    q.pop() ;
    for( int i = 0 ; i < 4 ; i++ )
    {
      pair<int , int> v = {u.first + cx[i] , u.second + cy[i]} ;
      if(v.first < 1 || v.first > n || v.second < 1 || v.second > m || vis[v.first][v.second] || c[v.first][v.second] == '#') continue ;
      vis[v.first][v.second] = 1 ;
      q.push(v) ;
    }
  }
}
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= m ; j++ ) cin >> c[i][j] ;
  }
  bfs() ;
  cout << (vis[n][m] ? "Yes" : "No") ;
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