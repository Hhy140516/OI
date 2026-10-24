#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , a , b ;
int s[1005] ;
void solve()
{
  cin >> n >> a >> b ;
  for( int i = 1 ; i <= n ; i++ )
  {
    cin >> s[i] ;
  }
  for( int i = 1 ; i <= n ; i++ )
  {
    if(s[i] == 1)
    {
      if(a) a-- ;
      else if(b) b-- ;
      else
      {
        cout << i - 1 << "\n" ;
        return ;
      }
    }
    else
    {
      if(b) b-- ;
      else
      {
        cout << i - 1 << "\n" ;
        return ;
      }
    }
  }
  cout << n << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}