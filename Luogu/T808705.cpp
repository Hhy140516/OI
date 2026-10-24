#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
struct node
{
  ll a , b , c ;
}nd[1000005] ;
void solve()
{
  cin >> n >> m ;
  for( int i = 1 ; i <= n ; i++ ) cin >> nd[i].a ;
  for( int i = 1 ; i <= n ; i++ ) cin >> nd[i].b ;
  for( int i = 1 ; i <= n ; i++ ) cin >> nd[i].c ;
  if(n <= 1000 && m <= 1000)
  {
    while(m--)
    {
      int opt ;
      cin >> opt ;
      if(opt == 1)
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( int i = 1 ; i <= n ; i++ )
        {
          if(nd[i].a == x)
          {
            nd[i].b = y , nd[i].c = z ;
          }
        }
      }
      else if(opt == 2)
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( int i = 1 ; i <= n ; i++ )
        {
          if(nd[i].b == x)
          {
            nd[i].a = y , nd[i].c = z ;
          }
        }
      }
      else
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( int i = 1 ; i <= n ; i++ )
        {
          if(nd[i].c == x)
          {
            nd[i].a = y , nd[i].b = z ;
          }
        }
      }
      ll suma = 0 , sumb = 0 , sumc = 0 ;
      for( int i = 1 ; i <= n ; i++ )
      {
        suma += nd[i].a , sumb += nd[i].b , sumc += nd[i].c ;
      }
      cout << suma << " " << sumb << " " << sumc << "\n" ;
    }
  }
  else
  {
    set<int> sta[105] , stb[105] , stc[105] ;
    ll suma = 0 , sumb = 0 , sumc = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
      suma += nd[i].a , sumb += nd[i].b , sumc += nd[i].c ;
      sta[nd[i].a].insert(i) ;
      stb[nd[i].b].insert(i) ;
      stc[nd[i].c].insert(i) ;
    }
    while(m--)
    {
      int opt ;
      cin >> opt ;
      if(opt == 1)
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( auto it : sta[x] )
        {
          sumb -= nd[it].b , sumc -= nd[it].c ;
          stb[nd[it].b].erase(it) , stc[nd[it].c].erase(it) ;
          nd[it].b = y , nd[it].c = z ;
          stb[y].insert(it) , stc[z].insert(it) ;
          sumb += y , sumc += z ;
        }
      }
      else if(opt == 2)
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( auto it : stb[x] )
        {
          suma -= nd[it].a , sumc -= nd[it].c ;
          sta[nd[it].a].erase(it) , stc[nd[it].c].erase(it) ;
          nd[it].a = y , nd[it].c = z ;
          sta[y].insert(it) , stc[z].insert(it) ;
          suma += y , sumc += z ;
        }
      }
      else
      {
        int x , y , z ;
        cin >> x >> y >> z ;
        for( auto it : stc[x] )
        {
          suma -= nd[it].a , sumb -= nd[it].b ;
          sta[nd[it].a].erase(it) , stb[nd[it].b].erase(it) ;
          nd[it].a = y , nd[it].b = z ;
          sta[y].insert(it) , stb[z].insert(it) ;
          suma += y , sumb += z ;
        }
      }   
      cout << suma << " " << sumb << " " << sumc << "\n" ;
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