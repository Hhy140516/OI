#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 10005 , MOD = 19260817 ;
string a , b ;
ll ksm(ll a , ll b)
{
  ll mul = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a % MOD ;
    a = a * a % MOD ;
    b >>= 1 ;
  }
  return mul ;
}
ll get(string s)
{
  ll res = 0 ;
  for( char c : s ) res = (res * 10 + c - '0') % MOD ;
  return res ;
}
void solve()
{
  cin >> a >> b ;
  ll A = get(a) , B = get(b) ;
  if(B == 0)
  {
    cout << "Angry!" ;
    return ;
  }
  cout << A * ksm(B , MOD - 2) % MOD ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}