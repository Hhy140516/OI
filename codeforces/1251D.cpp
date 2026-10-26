#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n , M ;
ll s ;
struct node
{
  int l , r ;
}nd[kMaxN] ;
bool check(int mid)
{
  int cnt = 0 ;
  ll res = 0 ;
  vector<int> ve ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(nd[i].r < mid)
    {
      res += nd[i].l ;
    }
    else if(nd[i].l > mid)
    {
      res += nd[i].l ;
      cnt++ ;
    }
    else
    {
      ve.push_back(nd[i].l) ;
    }
  }
  sort(ve.begin() , ve.end() , greater<int>()) ;
  int nd = max(M - cnt , 0) ;
  if(nd > ve.size()) return 0 ;
  for( int i = 0 ; i < ve.size() ; i++ )
  {
    if(i < nd)
    {
      res += mid ;
    }
    else res += ve[i] ;
  }
  return res <= s ;
}
void solve()
{
  cin >> n >> s ;
  for( int i = 1 ; i <= n ; i++ ) cin >> nd[i].l >> nd[i].r ;
  M = (n + 1) / 2 ;
  int l = 0 , r = 1e9 ;
  while(l < r)
  {
    int mid = l + r + 1 >> 1 ;
    if(check(mid)) l = mid ;
    else r = mid - 1 ;
  }
  cout << l << "\n" ;
}
signed main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
	int oT_To = 1 ;
	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}