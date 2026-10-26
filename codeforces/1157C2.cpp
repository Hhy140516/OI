#include<bits/stdc++.h> 
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 , MOD = 1e9 + 7 ;
int n ;
int a[kMaxN] ;
void solve()
{
	cin >> n ;
  int maxn = 0 ;
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i] ;
    maxn = max(maxn , a[i]) ;
	} 
  int l = 1 , r = n ;
  string s ;
  int lst = -1 ;
  while(l <= r)
  {
    if(min(a[l] , a[r]) > lst)
    {
      if(a[l] == a[r])
      {
        int maxn1 = 1 , maxn2 = 1 ;
        for( int i = l + 1 ; i <= n ; i++ )
        {
          if(a[i - 1] >= a[i])
          {
            maxn1 = i - l ;
            break ;
          }
        }
        for( int i = r - 1 ; i >= 1 ; i-- )
        {
          if(a[i + 1] >= a[i])
          {
            maxn2 = r - i ;
            break ;
          }
        }
        if(maxn1 >= maxn2)
        {
          for( int i = 1 ; i <= maxn1 ; i++ ) s += "L" ;
        }
        else 
        {
          for( int i = 1 ; i <= maxn2 ; i++ ) s += "R" ;
        }
        break ;
      }
      else if(a[l] < a[r])
      {
        lst = a[l] ;
        s += "L" ;
        l++ ;
      }
      else
      {
        lst = a[r] ;
        s += "R" ;
        r-- ;
      }
    }
    else
    {
      if(max(a[l] , a[r]) <= lst) break ;
      if(a[l] > lst)
      {
        lst = a[l] ;
        s += "L" ;
        l++ ;
      }
      else
      {
        lst = a[r] ;
        s += "R" ;
        r-- ;
      }
    }
  }
  cout << s.size() << "\n" << s ;
}
signed main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  // freopen(".in" , "r" , stdin) ;
  // freopen(".out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}