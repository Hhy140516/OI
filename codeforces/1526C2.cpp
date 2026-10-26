#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n ;
int a[kMaxN] ;
priority_queue<ll , vector<ll> , greater<ll> > pq ;
void solve()
{
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i] ;
	} 
	ll nw = 0 ;
	for( int i = 1 ; i <= n ; i++ )
	{
		nw += a[i] ;
		pq.push(a[i]) ;
		if(nw < 0) 
		{
			nw -= pq.top() ;
			pq.pop() ;
		}
	}
	cout << pq.size() ;
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