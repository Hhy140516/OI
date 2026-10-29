#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std ;
int n , q ;
ll c[2000005] , a[2000005] , ans[2000005] ;
#define lowbit(x) (x & -x)
struct node
{
  int x , pos , id , f ;
}_c[4000005] ;
void update(int id , ll x)
{
  while(id <= 2000000)
  {
    c[id] += x ;
    id += lowbit(id) ;
  }
}
ll query(int id)
{
  ll sum = 0 ;
  while(id >= 1)
  {
    sum += c[id] ;
    id -= lowbit(id) ;
  }
  return sum ;
}
bool cmp(node x , node y)
{
  return x.x < y.x ;
}
void solve()
{
  cin >> n >> q ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    cin >> a[i] ;
  }
  int cnt = 0 ;
  for( int i = 1 ; i <= q ; i++ )
  {
    int l , r , x ;
    cin >> l >> r >> x ;
    _c[++cnt] = {l - 1 , x , i , -1} ;
    _c[++cnt] = {r , x , i , 1} ;
  }
  sort(_c + 1 , _c + cnt + 1 , cmp) ;
  for( int i = 1 ; i <= cnt ; i++ )
  {
    for( int j = _c[i - 1].x + 1 ; j <= _c[i].x  ; j++ )
    {
      update(a[j] , 1) ;
    }
    ans[_c[i].id] += _c[i].f * query(_c[i].pos) ;
  }
  for( int i = 1 ; i <= q ; i++ ) cout << ans[i] << "\n" ;
}
signed main()
{
  int t = 1 ;
  // cin >> t ;
  while(t--) solve() ;
  return 0 ;
}