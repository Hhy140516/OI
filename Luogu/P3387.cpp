#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e4 + 5 , kMaxM = 1e5 + 5 ;
int n , m ;
ll a[kMaxN] ;
int dfn[kMaxN] , low[kMaxN] , tim ;
bool vis[kMaxN] ;
stack<int> st ;
int head[kMaxN] ;
struct edge
{
  int v , nxt ;
}edg[kMaxM] ;
int cnt = 0 ;
void add_edge(int u , int v)
{
  edg[++cnt] = {v , head[u]} ;
  head[u] = cnt ;
}
int scc ;
ll sum[kMaxN] ;
int color[kMaxN] ; 
void tarjan(int u)
{
  dfn[u] = low[u] = ++tim ;
  st.push(u) ;
  vis[u] = 1 ;
  for( int i = head[u] ; i ; i = edg[i].nxt )
  {
    int v = edg[i].v ;
    if(!dfn[v])
    {
      tarjan(v) ;
      low[u] = min(low[u] , low[v]) ;
    }
    else if(vis[v])
    {
      low[u] = min(low[u] , dfn[v]) ;
    }
  }
  if(dfn[u] == low[u])
  {
    scc++ ;
    while(!st.empty())
    {
      color[st.top()] = scc ;
      sum[scc] += a[st.top()] ;
      vis[st.top()] = 0 ;
      if(u == st.top())
      {
        st.pop() ;
        break ;
      }
      st.pop() ;
    }
  }
}
vector<pair<int , int> > ve ;
int in[kMaxN] ;
vector<int> G[kMaxN] ;
ll dp[kMaxN] ;
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
  for( int i = 1 ; i <= m ; i++ )
  {
    int u , v ;
    cin >> u >> v ;
    ve.push_back({u , v}) ;
    add_edge(u , v) ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    if(!dfn[i])
    {
      tarjan(i) ;
    }
  }
  for( int i = 0 ; i < ve.size() ; i++ )
  {
    if(color[ve[i].first] != color[ve[i].second])
    {
      in[color[ve[i].second]]++ ;
      G[color[ve[i].first]].push_back({color[ve[i].second]}) ;
    }
  }
  queue<int> q ;
  for( int i = 1 ; i <= scc ; i++ )
  {
    dp[i] = sum[i] ;
    if(!in[i]) q.push(i) ;
  }
  while(!q.empty())
  {
    int u = q.front() ;
    q.pop() ;
    for( int i = 0 ; i < G[u].size() ; i++ )
    {
      int v = G[u][i] ;
      dp[v] = max(dp[v] , dp[u] + sum[v]) ;
      in[v]-- ;
      if(in[v] == 0) q.push(v) ;
    }
  }
  ll ans = 0 ;
  for( int i = 1 ; i <= scc ; i++ ) ans = max(ans , dp[i]) ;
  cout << ans ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}