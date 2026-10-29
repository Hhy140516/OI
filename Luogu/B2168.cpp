#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 100005 ;
int n , N ;
string s[kMaxN] , as[kMaxN] ;
priority_queue<pair<ll , int> , vector<pair<ll , int> > , greater<pair<ll , int> > > pq ;
struct node
{
  int v , w ;
};
vector<node> G[kMaxN] ;
void dfs(int u , string s)
{
  if(u <= n) as[u] = s ;
  for( int i = 0 ; i < G[u].size() ; i++ )
  {
    int v = G[u][i].v ;
    string S = s + char(G[u][i].w + '0') ;
    dfs(v , S) ;
  }
}
void solve()
{
  cin >> n ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> s[i] ;
    int x ;
    cin >> x ;
    pq.push({x , i}) ;
  }
  if(n == 1)
  {
    cout << s[1] << " 0" ;
    return ;
  }
  N = n ;
  while(pq.size() > 1)
  {
    auto x1 = pq.top() ;
    pq.pop() ;
    auto x2 = pq.top() ;
    pq.pop() ;
    pq.push({x1.first + x2.first , ++N}) ;
    G[N].push_back({x1.second , 0}) ;
    G[N].push_back({x2.second , 1}) ;
  }
  dfs(N , "") ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cout << s[i] << " " << as[i] << "\n" ;
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