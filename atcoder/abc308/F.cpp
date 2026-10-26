#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n , m ;
int a[kMaxN] ;
struct node
{
  int l , d ;
  bool operator < (const node &a) const
  {
    return l < a.l ;
  }
}nd[kMaxN] ;
void solve()
{
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i] ;
	} 
  sort(a + 1 , a + n + 1) ;
  for( int i = 1 ; i <= m ; i++ )
	{
		cin >> nd[i].l ;
	} 
  for( int i = 1 ; i <= m ; i++ )
	{
		cin >> nd[i].d ;
	} 
  sort(nd + 1 , nd + m + 1) ;
	int nw = 1 ;
  priority_queue<int> pq ;
  for( int i = 1 ; i <= n ; i++ )
  {
    while(nw <= m && nd[nw].l <= a[i]) pq.push(nd[nw++].d) ;
    if(!pq.empty())
    {
      a[i] -= pq.top() ;
      pq.pop() ;
    }
  }
  ll as = 0 ;
  for( int i = 1 ; i <= n ; i++ ) as += a[i] ;
  cout << as ;
}
signed main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}