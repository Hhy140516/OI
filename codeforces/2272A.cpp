#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , kMaxK = 505 ;
int n , k ;
int a[kMaxN] ;
bool fl[kMaxN] ;
int maxn = -1 ;
pair<int , int> as ;
void solve()
{
  cin >> n >> k ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> a[i] ;
  }
  priority_queue<int> pq ;
  int mex = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    fl[a[i]] = 1 ;
    while(fl[mex]) mex++ ;
    pq.push(mex) ;
  }
  maxn = -1 ;
  int K = k ;
  while(!pq.empty())
  {
    K-- ;
    if(K == 0) 
    {
      if(pq.top() > maxn)
      {
        maxn = pq.top() ;
        as = {-1 , -1} ;
      }
    }
    pq.pop() ;
  }
  for( int i = 0 ; i < n ; i++ ) fl[i] = 0 ;
  for( int l = 1 ; l < n ; l++ )
  {
    for( int r = l + 1 ; r <= n ; r++ )
    {
      swap(a[l] , a[r]) ;
      int mex = 0 ;
      for( int i = 1 ; i <= n ; i++ )
      {
        fl[a[i]] = 1 ;
        while(fl[mex]) mex++ ;
        pq.push(mex) ;
      }
      int K = k ;
      while(!pq.empty())
      {
        K-- ;
        if(K == 0) 
        {
          if(pq.top() > maxn)
          {
            maxn = pq.top() ;
            as = {l , r} ;
          }
        }
        pq.pop() ;
      }
      for( int i = 0 ; i < n ; i++ ) fl[i] = 0 ;
      swap(a[l] , a[r]) ;
    }
  }
  if(as == make_pair(-1 , -1)) cout << "-1\n" ;
  else cout << as.first << " " << as.second << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}