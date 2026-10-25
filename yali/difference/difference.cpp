#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , x ;
int a[100005] , p[100005] ;
bool f[100005] ;
bool fl = 0 ;
void dfs(int step)
{
  if(!fl) return ;
  if(step > n)
  {
    fl = 0 ;
    cout << "yes\n" ;
    for( int i = 1 ; i <= n ; i++ ) cout << p[i] << " " ;
    cout << "\n" ;
    return ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    if(!f[i])
    {
      if(a[i] == p[step - 1]) continue ;
      f[i] = 1 ;
      p[step] = a[i] ;
      dfs(step + 1) ;
      f[i] = 0 ;
    }
  }
}
void solve()
{ 
  cin >> n >> x ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  if(x < 0)
  {
    sort(a + 1 , a + n + 1) ;
    cout << "yes\n" ;
    for( int i = 1 ; i <= n ; i++ ) cout << a[i] << " " ;
    cout << "\n" ;
  }
  else if(x > 0)
  {
    sort(a + 1 , a + n + 1 , greater<int>()) ;
    if(a[1] == x)
    {
      int id = 0 ;
      for( int i = 1 ; i <= n ; i++ )
      {
        if(a[i] != x && a[i] != 0)
        {
          id = i ;
          break ;
        }
      }
      if(id == 0)
      {
        cout << "no\n" ;
        return ;
      }
      cout << "yes\n" ;
      cout << a[id] << " " ;
      for( int i = 1 ; i <= n ; i++ )
      {
        if(i == id) continue ;
        cout << a[i] << " " ;
      }
      cout << "\n" ;
    }
    else
    {
      cout << "yes\n" ;
      for( int i = 1 ; i <= n ; i++ ) cout << a[i] << " " ;
      cout << "\n" ;
    }
  }
  else
  {
    p[0] = x ;
    fl = 1 ;
    dfs(1) ;
    if(fl) cout << "no\n" ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("difference.in" , "r" , stdin) ;
  freopen("difference.out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}