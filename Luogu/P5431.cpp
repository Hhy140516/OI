#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , p , k ;
ll a[5000005] , inv[5000005] , ifac[5000005] ;
ll ksm(ll a , int b = p - 2)
{
  ll mul = 1 ;
  while(b)
  {
    if(b & 1) mul = mul * a % p ;
    a = a * a % p ;
    b >>= 1 ;
  }
  return mul ;
}
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {//读入一个 64 位无符号整数
	unsigned long long x=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)) x=x*10+(ch^48),ch=gc();
	return x;
}
void solve()
{
  n = rd() , p = rd() , k = rd() ;
  ll res = 1 ;
  for( int i = 1 ; i <= n ; i++ ) 
  {
    a[i] = rd() ;
    res = res * a[i] % p ;
  }
  ifac[n] = ksm(res) ;
  for( int i = n ; i >= 1 ; i-- ) ifac[i - 1] = ifac[i] * a[i] % p ;
  res = 1 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    inv[i] = ifac[i] * res % p ;
    res = res * a[i] % p ;
  }
  ll as = 0 , K = 1 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    K = K * k % p ;
    as = (as + (K * inv[i] % p)) % p ;
  }
  cout << as ;
}
int main()
{
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}