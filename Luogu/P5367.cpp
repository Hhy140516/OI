#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ;
int n ;
ll fac[1000005] ;
int a[1000005] ;
struct cTr
{
  vector<int> c ;
  cTr()
  {
    c.resize(1000005) ;
  }
  inline int lowbit(int x)
  {
    return x & -x ;
  }
  void update(int id , int x)
  {
    while(id <= 1000000)
    {
      c[id] += x ;
      id += lowbit(id) ;
    }
  }
  int query(int id)
  {
    int sum = 0 ;
    while(id)
    {
      sum += c[id] ;
      id -= lowbit(id) ;
    }
    return sum ;
  }
}Tr ;
void solve()
{
  cin >> n ;
  fac[0] = 1 ;
  for( int i = 1 ; i <= n ; i++ ) fac[i] = fac[i - 1] * i % MOD ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    cin >> a[i] ;
    Tr.update(a[i] , 1) ;
  }
  ll as = 0 ;
  for( int i = 1 ; i <= n ; i ++ )
  {
    Tr.update(a[i] , -1) ;
    as = (as + (Tr.query(a[i]) * fac[n - i] % MOD)) % MOD ;
  }
  cout << as + 1 ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}