#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int MOD = 1e9 + 7 ;
int n , x , k ;
string s ;
int a[4][4] ;
map<char , int> id ;
void dfs(int step , int cnt)
{
  if(!k) return ;
  if(step == s.size())
  {
    if(cnt >= x)
    {
      k-- ;
      if(k == 0)
      {
        cout << s ;
        exit(0) ;
      }
    }
    return ;
  }
  if(s[step] != '?')
  {
    dfs(step + 1 , (step == 0 ? cnt : cnt + a[id[s[step - 1]]][id[s[step]]])) ;
  }
  else
  {
    for( int i = 0 ; i < 4 ; i++ )
    {
      s[step] = "PONI"[i] ;
      dfs(step + 1 , (step == 0 ? cnt : cnt + a[id[s[step - 1]]][id[s[step]]])) ;
      s[step] = '?' ;
    }
  }
}
void solve()
{ 
  id['P'] = 0 , id['O'] = 1 , id['N'] = 2 , id['I'] = 3 ;
  cin >> n >> x >> k ;
  cin >> s ;
  cin >> a[2][2] >> a[2][1] >> a[2][3] >> a[2][0] ;
  cin >> a[1][2] >> a[1][1] >> a[1][3] >> a[1][0] ;
  cin >> a[3][2] >> a[3][1] >> a[3][3] >> a[3][0] ;
  cin >> a[0][2] >> a[0][1] >> a[0][3] >> a[0][0] ;
  dfs(0 , 0) ;
  cout << -1 ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  freopen("travel.in" , "r" , stdin) ;
  freopen("travel.out" , "w" , stdout) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}