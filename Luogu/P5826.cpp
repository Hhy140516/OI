#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , q , m ;
vector<int> ve[100005] ;
void solve()
{
  cin >> n >> n >> q >> m ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    int x ;
    cin >> x ;
    ve[x].push_back(i) ;
  }
  while(q--)
  {
    int lst = 0 ;
    int l ;
    cin >> l ;
    bool fl = 1 ;
    while(l--)
    {
      int x ;
      cin >> x ;
      if(!fl) continue ;
      int pos = upper_bound(ve[x].begin() , ve[x].end() , lst) - ve[x].begin() ;
      if(pos == ve[x].size()) fl = 0 ;
      else lst = ve[x][pos] ;
    }
    if(fl) cout << "Yes\n" ;
    else cout << "No\n" ;
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