#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
const double eps = 1e-5 ;
int n , m , L , V ;
struct car
{
  int d , v , a ;
}nd[kMaxN] ;
int p[kMaxN] ;
bool cmp(pair<int , int> x , pair<int , int> y)
{
  if(x.first == y.first) return x.second > y.second ;
  return x.first < y.first ;
}
bool fl[kMaxN] ;
void solve() 
{
  cin >> n >> m >> L >> V ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> nd[i].d >> nd[i].v >> nd[i].a ;
  }
  for( int i = 1 ; i <= m ; i++ ) cin >> p[i] ;
  int cnt = 0 ;
  vector<pair<int , int> > ve ;
  for( int i = 1 ; i <= n ; i++ )
  {
    bool fl = 0 ;
    if(nd[i].v > V && nd[i].a >= 0)
    {
      int pos = lower_bound(p + 1 , p + m + 1 , nd[i].d) - p ;
      if(pos <= m)
      {
        fl = 1 ;
        ve.push_back({pos , m}) ;
      }
    }
    else if(nd[i].v > V && nd[i].a < 0)
    {
      int l = lower_bound(p + 1 , p + m + 1 , nd[i].d) - p ;
      int L = l - 1 , R = m ;
      while(L < R)
      {
        int mid = L + R + 1 >> 1 ;
        if(nd[i].v * nd[i].v + 2 * nd[i].a * (p[mid] - nd[i].d) - V * V > 0) 
        {
          L = mid ;
        }
        else R = mid - 1 ;
      }
      int r = L ;
      if(l <= r)
      {
        fl = 1 ;
        ve.push_back({l , r}) ;
      }
    }
    else if(nd[i].v <= V && nd[i].a <= 0)
    {
      fl = 0 ;
    }
    else
    {
      int pos = lower_bound(p + 1 , p + m + 1 , nd[i].d) - p ;
      int L = pos , R = m + 1 , r = m ;
      while(L < R)
      {
        int mid = L + R >> 1 ;
        if(nd[i].v * nd[i].v + 2 * nd[i].a * (p[mid] - nd[i].d) - V * V > 0)
        {
          R = mid ;
        }
        else L = mid + 1 ;
      }
      int l = L ;
      if(l <= r)
      {
        fl = 1 ;
        ve.push_back({l , r}) ;
      }
    }
    cnt += fl ;
  }
  cout << cnt << " " ;
  sort(ve.begin() , ve.end() , cmp) ;
  int minn = 1e9 ;
  for( int i = ve.size() - 1 ; i >= 0 ; i-- )
  {
    fl[i] = 0 ;
    if(ve[i].second > minn) fl[i] = 1 ;
    minn = min(minn , ve[i].second) ;
  }
  int del = 0 , as = 0 ;
  for( int i = 0 ; i < ve.size() ; i++ )
  {
    if(fl[i]) continue ;
    if(del < ve[i].first)
    {
      del = ve[i].second ;
      as++ ;
    }
  }
  cout << m - as << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}