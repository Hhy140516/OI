#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 ;
const unsigned ll MOD1 = 1e9 + 7 , MOD2 = 998244353 , base1 = 131 , base2 = 13331 ;
int n ;
int a[kMaxN] ;
unsigned ll p1[1000005] , p2[1000005] , sx[kMaxN] , sy[kMaxN] ;
map<pair<unsigned ll , unsigned ll> , ll> mp ;
map<int  , int> f ;
void init()
{
  p1[0] = p2[0] = 1 ;
  for( int i = 1 ; i <= 1e6 ; i++ )
  {
    p1[i] = p1[i - 1] * base1 % MOD1 ;
    p2[i] = p2[i - 1] * base2 % MOD2 ;
  }
}
void solve()
{
  mp.clear() ;
  f.clear() ;
  cin >> n ;
  sx[0] = sy[0] = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x ;
    cin >> x ;
    unsigned ll X = 0 , Y = 0 ;
    vector<int> ve ;
    for( int j = 2 ; j * j <= x ; j++ )
    {
      int cnt = 0 ;
      while(x % j == 0)
      {
        cnt++ ;
        x /= j ;
      }
      if(cnt % 2)
      {
        ve.push_back(j) ;
        X += p1[j - 1] ;
        X %= MOD1 ;
        Y += p2[j - 1] ;
        Y %= MOD2 ;
      }
    }
    if(x > 1)
    {
      ve.push_back(x) ;
      X += p1[x - 1] ;
      X %= MOD1 ;
      Y += p2[x - 1] ;
      Y %= MOD2 ;
    }
    mp[{X , Y}]++ ;
    sx[i] = sx[i - 1] , sy[i] = sy[i - 1] ;
    for( int j = 0 ; j < ve.size() ; j++ )
    {
      if(f[ve[j]])
      {
        sx[i] = (sx[i] + MOD1 - p1[ve[j] - 1]) % MOD1 ;
        sy[i] = (sy[i] + MOD2 - p2[ve[j] - 1]) % MOD2 ;
      }
      else
      {
        sx[i] += p1[ve[j] - 1] ;
        sx[i] %= MOD1 ;
        sy[i] += p2[ve[j] - 1] ;
        sy[i] %= MOD2 ;
      }
      f[ve[j]] ^= 1 ;
    }
    // cout << sx[i] << " " << sy[i] << "\n" ;
  }
  ll as = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    as += mp[{sx[i] , sy[i]}] ;
  }
  cout << as << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//  freopen(".in" , "r" , stdin) ;
//  freopen(".out" , "w" , stdout) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  init() ;
  while(oT_To--) solve() ;
  return 0 ;
}