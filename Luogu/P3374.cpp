#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n , q ;
struct cTr
{
  vector<int> c ;
  cTr()
  {
    c.resize(kMaxN) ;
  }
  inline int lowbit(int x)
  {
    return x & -x ;
  }
  void update(int x , int k)
  {
    while(x <= n)
    {
      c[x] += k ;
      x += lowbit(x) ;
    }
  }
  int get(int x)
  {
    int sum = 0 ;
    while(x)
    {
      sum += c[x] ;
      x -= lowbit(x) ;
    }
    return sum ;
  }
  int query(int l , int r)
  {
    return get(r) - get(l - 1) ;
  }
};
cTr Tr ;
void solve()
{
 cin >> n >> q ;
 for( int i = 1 ; i <= n ; i++ )
 {
  int x ;
  cin >> x ;
  Tr.update(i , x) ;
 }
 while(q--)
 {
  int opt ;
  cin >> opt ;
  if(opt == 1)
  {
    int x , k ;
    cin >> x >> k ;
    Tr.update(x , k) ;
  }
  else
  {
    int l , r ;
    cin >> l >> r ;
    cout << Tr.query(l , r) << "\n" ;
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