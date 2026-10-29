#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int kMaxN = 1e6 + 5 ;
int n ;
int l[kMaxN] , r[kMaxN] ;
void pre(int u)
{
  if(!u) return ;
  cout << u << " " ;
  pre(l[u]) ;
  pre(r[u]) ;
}
void mid(int u)
{
  if(!u) return ;
  mid(l[u]) ;
  cout << u << " " ;
  mid(r[u]) ;
}
void suf(int u)
{
  if(!u) return ;
  suf(l[u]) ;
  suf(r[u]) ;
  cout << u << " " ;
}
void solve()
{
	cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> l[i] >> r[i] ;
  pre(1) ;
  cout << "\n" ;
  mid(1) ;
  cout << "\n" ;
  suf(1) ;
  cout << "\n" ;
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}