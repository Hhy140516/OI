#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , x ;
int a[100005] ;
map<int , int> mp ;
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
    mp.clear() ;
    for( int i = 1 ; i <= n ; i++ ) mp[a[i]]++ ;
    int maxn = 0 , id = -1 ;
    for( auto p : mp )
    {
      if(p.second > maxn)
      {
        maxn = p.second ;
        id = p.first ;
      }
    }
    if(maxn > (n + 1) / 2 || (maxn > n / 2 && id == 0))
    {
      cout << "no\n" ;
      return ;
    }
    priority_queue<pair<int , int> > pq ;
    for( auto p : mp ) pq.push({p.second , p.first}) ;
    cout << "yes\n" ;
    int lst = -1 ;
    for( int i = 1 ; i <= n ; i++ )
    {
      auto x = pq.top() ; 
      pq.pop() ;
      if(x.second == lst || (i == 1 && x.second == 0))
      {
        auto y = pq.top() ; 
        pq.pop() ;
        pq.push(x) ;
        x = y ;
      }
      cout << x.second << " " ;
      lst = x.second ;
      x.first-- ;
      if(x.first > 0) pq.push(x) ;
    }
    cout << "\n" ;
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