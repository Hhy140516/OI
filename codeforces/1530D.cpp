#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n ;
int a[kMaxN] ;
int p[kMaxN] ;
int f[kMaxN] , nxt[kMaxN] ;
map<int , int> mp ;
set<int> st ;
void solve()
{ 
  cin >> n ;
  mp.clear() ;
  st.clear() ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    p[i] = 0 ;
    cin >> a[i] ;
    st.insert(i) ;
  }
  for( int i = n ; i >= 1 ; i-- )
  {
    nxt[i] = f[a[i]] ;
    f[a[i]] = i ;
  }
  int as = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    if(mp[a[i]] == 0)
    {
      mp[a[i]] = i ;
      p[i] = a[i] ;
      st.erase(a[i]) ;
    }
    else
    {
      // cout << i << " " ;
      p[mp[a[i]]] = *st.begin() ;
      mp[*st.begin()] = mp[a[i]] ;
      st.erase(st.begin()) ;
      mp[a[i]] = i ;
      p[i] = a[i] ;
    }
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    if(p[i] != i) continue ;
    swap(p[i] , p[nxt[i]]) ;
  }
  int cnt = 0 ;
  for( int i = 1 ; i <= n ; i++ ) cnt += (p[i] == a[i]) ;
  cout << cnt << "\n" ;
  for( int i = 1 ; i <= n ; i++ ) cout << p[i] << " " ;
  cout << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}