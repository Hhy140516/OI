#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 ;
int n , m ;
int h[kMaxN] , p[kMaxN] ;
priority_queue<pair<int , int> > pq[2] ;
void solve()
{
  cin >> n >> m ;
  while(!pq[0].empty()) pq[0].pop() ;
  while(!pq[1].empty()) pq[1].pop() ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    int x ;
    cin >> x ;
    pq[0].push({x , i}) ;
  }
  for( int i = 1 ; i <= m ; i++ ) cin >> h[i] ;
  int lst = 0 ;
  for( int i = 1 ; i <= m ; i++ )
  {
    if(abs(h[i] - lst) != 1)
    {
      cout << "NO\n" ;
      return ;
    }
    if(h[i] > lst)
    {
      if(pq[0].empty())
      {
        cout << "NO\n" ;
        return ;
      }
      auto it = pq[0].top() ;
      pq[0].pop() ;
      it.first-- ;
      p[i] = it.second ;
      if(it.first) pq[1].push(it) ;
    }
    else
    {
      if(pq[1].empty())
      {
        cout << "NO\n" ;
        return ;
      }
      auto it = pq[1].top() ;
      pq[1].pop() ;
      it.first-- ;
      p[i] = it.second ;
      if(it.first) pq[0].push(it) ;
    }
    lst = h[i] ;
  }
  cout << "YES\n" ;
  for( int i = 1 ; i <= m ; i++ ) cout << p[i] << " " ;
  cout << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("oddrecords.in" , "r" , stdin) ;
  freopen("oddrecords.out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}
