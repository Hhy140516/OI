#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e4 + 5 , kMaxM = 2e5 + 5 ;
int n , m ;
int dfn[kMaxN] , low[kMaxN] , tim ;
int head[kMaxN] ;
struct node
{
  int v , nxt ;
}edg[kMaxM] ;
int cnt = 0 ;
void add_edge(int u , int v)
{
  edg[cnt] = {v , head[u]} ;
  head[u] = cnt ;
  cnt++ ;
}
int root ;
bool vis[kMaxN] ;
void tarjan(int u)
{
  dfn[u] = low[u] = ++tim ;
  int ans = 0 ;
	for( int i = head[u] ; i ; i = edg[i].nxt )
	{
		int v = edg[i].v ;
		if(dfn[v] == 0) 
		{
			tarjan(v) ;
			low[u] = min(low[u] , low[v]) ;
			if(low[v] >= dfn[u])
			{
				ans++ ;
				if(u != root || ans >= 2) vis[u] = 1 ;
			}
		}
		else
		{
			low[u] = min(low[u] , dfn[v]) ;
		}
	}
}
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= m ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    add_edge(u , v) ;
    add_edge(v , u) ;
  }
  for( int i = 1 ; i <= n ; i++ )
	{
		if(dfn[i] == 0) 
		{
			root = i ;
			tarjan(i) ;
		}
	}
  int res = 0 ;
	for( int i = 1 ; i <= n ; i++ )
	{
		if(vis[i]) res++ ;
	}
	cout << res << "\n" ;
	for( int i = 1 ; i <= n ; i++ )
	{
		if(vis[i])
		{
			cout << i << " " ;
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