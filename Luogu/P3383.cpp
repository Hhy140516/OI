#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , q ;
vector<int> ve ;
bool f[100000005] ;
void solve()
{
  cin >> n >> q ;
  for( int i = 2 ; i <= n ; i++ )
  {
    if(!f[i])
    {
      ve.push_back(i) ;
      for( int j = 2 * i ; j <= n ; j += i )
      {
        f[j] = 1 ;
      }
    }
  }
  while(q--)
  {
    int x ;
    cin >> x ;
    cout << ve[x - 1] << "\n" ;
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