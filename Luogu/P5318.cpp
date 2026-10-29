#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int kMaxN = 1e3 + 5 ;
int n , m ;
vector<int> G[100005] ;
bool vis[100005] ;
void dfs(int u)
{
	cout << u << " " ;
	for( int i = 0 ; i < G[u].size() ; i++ )
	{
		if(vis[G[u][i]] == 0)
		{
			vis[G[u][i]] = 1 ;
			dfs(G[u][i]) ;
		}
	}
}
void bfs(int u)
{
	queue<int> Q ;
	Q.push(u) ;
	vis[u] = 1 ;
	while(!Q.empty())
	{
		int v = Q.front() ;
		Q.pop() ;
		cout << v << " " ;
		for( int i = 0 ; i < G[v].size() ; i++ )
		{
			if(vis[G[v][i]] == 0)
			{
				vis[G[v][i]] = 1 ;
				Q.push(G[v][i]) ;
			}
		}
	}
}
void solve()
{
	cin >> n >> m ;
	for( int i = 1 ; i <= m ; i++ )
	{
		int x , y ;
		cin >> x >> y ;
		G[x].push_back(y) ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		sort(G[i].begin() , G[i].end()) ;
	}
	vis[1] = 1 ;
	dfs(1) ;
	cout << "\n" ;
	memset(vis , 0 , sizeof(vis)) ;
	bfs(1) ;
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