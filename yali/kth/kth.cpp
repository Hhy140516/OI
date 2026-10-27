#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e3 + 5 , kMaxK = 505 ;
int n , x , k ;
string s ;
ll dp[kMaxN][4] ;
ll a[4][4] ;
char c[4] = {'P' , 'O' , 'N' , 'I'} ;
bool check(int id , char c)
{
  return (s[id] == '?' || s[id] == c) ;
}
void dfs(int step , int lst , ll val , string s)
{
  if(!k) return ;
  if(step > n)
  {
    k-- ;
    if(k == 0)
    {
      cout << s ;
      exit(0) ;
    }
    return ;
  }
  for( int i = 0 ; i < 4 ; i++ )
  {
    if(!check(step , c[i])) continue ;
    if(val + a[lst][i] + dp[step + 1][i] < x) continue ;
    dfs(step + 1 , i , val + a[lst][i] , s + c[i]) ;
  }
}
void solve()
{
  cin >> n >> x >> k >> s ;
  cin >> a[2][2] >> a[2][1] >> a[2][3] >> a[2][0] ;
  cin >> a[1][2] >> a[1][1] >> a[1][3] >> a[1][0] ;
  cin >> a[3][2] >> a[3][1] >> a[3][3] >> a[3][0] ;
  cin >> a[0][2] >> a[0][1] >> a[0][3] >> a[0][0] ;
  s = ' ' + s ;
  memset(dp , -0x3f , sizeof dp) ;
  for( int i = 0 ; i < 4 ; i++ ) dp[n + 1][i] = 0 ;
  for( int i = n ; i >= 1 ; i-- )
  {
    for( int j = 0 ; j < 4 ; j++ )
    {
      for( int k = 0 ; k < 4 ; k++ )
      {
        if(!check(i , c[k])) continue ;
        dp[i][j] = max(dp[i][j] , dp[i + 1][k] + a[j][k]) ;
      }
    }
  }
  for( int i = 0 ; i < 4 ; i++ )
  {
    if(!check(1 , c[i])) continue ;
    if(dp[2][i] < x) continue ;
    string s ;
    s += c[i] ;
    dfs(2 , i , 0 , s) ;
  }
  cout << -1 ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("kth.in" , "r" , stdin) ;
  freopen("kth.out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}
