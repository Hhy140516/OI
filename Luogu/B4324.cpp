#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n , m ;
struct node
{
  int l , r ;
}a[kMaxN] ;
void del(int x)
{
  a[a[x].l].r = a[x].r ;
  a[a[x].r].l = a[x].l ;
}
void insert(int x , int y)
{
  a[y].l = x ;
  a[y].r = a[x].r ;
  a[a[x].r].l = y ;
  a[x].r = y ;
}
bool f[kMaxN] ;
void solve()
{
  cin >> n >> m ;
  a[0].r = 1 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    a[i].l = i - 1 ;
    a[i].r = i + 1 ;
  }
  a[n].r = 0 ;
  while(m--)
  {
    int opt ;
    cin >> opt ;
    if(opt == 1)
    {
      int x , y ;
      cin >> x >> y ;
      if(x == y || f[x]) continue ;
      del(x) ;
      insert(a[y].l , x) ;
    }
    else if(opt == 2)
    {
      int x , y ;
      cin >> x >> y ;
      if(x == y || f[x]) continue ;
      del(x) ;
      insert(y , x) ;
    } 
    else
    {
      int x ;
      cin >> x ;
      if(f[x]) continue ;
      del(x) ;
      f[x] = 1 ;
    }
  }
  int nw = a[0].r ; 
  if(nw == 0) 
  {
    cout << "Empty!" ;
    return ;
  }
  while(nw)
  {
    cout << nw << " " ;
    nw = a[nw].r ;
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while (oT_To--) solve() ;
  return 0 ;
}