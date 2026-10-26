#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n ;
pair<int , int> a[kMaxN] ;
void solve()
{
	cin >> n ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i].first >> a[i].second ;
	sort(a + 1 , a + n + 1) ;
	priority_queue<int , vector<int> , greater<int> > pq ;
	int pos = 1 ;
	for( int i = 1 ; i <= n || !pq.empty() ; )
	{
		if(pq.empty() && i <= n && pos < a[i].first)
		{
			pos = a[i].first ;
		}
		while(i <= n && a[i].first <= pos) pq.push(a[i++].second) ;
		if(pq.empty()) continue ;
		if(pq.top() < pos)
		{
			cout << "No\n" ;
			return ;
		}
		pq.pop() ;
		pos++ ;
	}
	cout << "Yes\n" ;
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