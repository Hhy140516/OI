#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
struct cTr
{
  vector<int> c ;
  cTr()
  {
    c.resize(n + 2) ;
  }
  inline int lowbit(int x)
  {
    return x & -x ;
  }
  void update(int x , int y)
  {
    while(x <= n)
    {
      c[x] += y ;
      x += lowbit(x) ;
    }
  }
  int query(int x)
  {
    int sum = 0 ;
    while(x)
    {
      sum += c[x] ;
      x -= lowbit(x) ;
    }
    return sum ;
  }
};
void solve()
{
  cin >> n >> m ;
  cTr Tr ;
  int lst = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x ;
    cin >> x ;
    Tr.update(i , x - lst) ;
    lst = x ;
  }
  // cout << Tr.query(1) ;
  while(m--)
  {
    int opt ;
    cin >> opt ;
    if(opt == 1)
    {
      int x , y , z ;
      cin >> x >> y >> z ;
      Tr.update(x , z) ;
      Tr.update(y + 1 , -z) ;
    }
    else
    {
      int x ;
      cin >> x ;
      cout << Tr.query(x) << "\n" ;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}