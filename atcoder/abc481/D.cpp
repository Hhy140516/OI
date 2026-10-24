#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 998244353 ; 
int n , m , s , t ;
struct edge
{
  int v , w ;
  bool operator<(const edge &a) const
  {
    return v < a.v ;
  }
};
vector<edge> G[200005] ;
bool vis[200005] ;
int d[200005] ;
struct node
{
	int u , w ;
	bool operator < (const node &a) const
	{
		return w > a.w ;
	}
};
void dij(int s)
{
	priority_queue<node> pq ;
	pq.push({s , 0}) ;
	memset(d , 0x3f , sizeof d) ;
	d[s] = 0 ;
	while(!pq.empty())
	{
		int u = pq.top().u ;
		pq.pop() ;
		if(vis[u]) continue ;
		vis[u] = 1 ;
		for( int i = 0 ; i < G[u].size() ; i++ )
		{
			int v = G[u][i].v , w = G[u][i].w ;
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w ;
				pq.push({v , d[v]}) ;
			}
		}
	}
}
void solve()
{
  cin >> n >> m >> s >> t ;
  for( int i = 1 ; i <= m ; i++ )
  {
  	int u , v ;
  	cin >> u >> v ;
  	G[u].push_back({v , 1}) ;
  }
  for( int i = 1 ; i <= n ; i++ ) 
  {
    sort(G[i].begin() , G[i].end()) ;
    if(!G[i].empty()) G[i][0].w = 0 ;
  }
  dij(s) ;
  if(d[t] == 0x3f3f3f3f) cout << -1 ;
  else cout << d[t] ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}