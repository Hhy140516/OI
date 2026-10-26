#include<bits/stdc++.h>
using namespace std ;
#define ll long long
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {//读入一个 64 位无符号整数
	unsigned long long x=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)) x=x*10+(ch^48),ch=gc();
	return x;
}
unsigned ll n ;
unsigned ll a[1 << 23] , key[1 << 23] ;
bool f[1 << 23] ;
const unsigned ll MOD = (1 << 23) - 1 , seed = chrono::steady_clock::now().time_since_epoch().count() ;
unsigned ll HSH(unsigned ll x)
{
  x += 5349205734364135ull ;
  x = (x ^ (x >> 16)) * 41236507398047ull ;
  x = (x ^ (x >> 20)) * 1289465843773656ull ;
  x = (x ^ (x >> 4)) * 2184632185672389026ull ;
  x *= 403673924ull ;
  return x ;
}
unsigned ll get(unsigned ll x)
{
  unsigned ll nw = (HSH(x) + seed) % MOD ;
  while(f[nw] && key[nw] != x) nw++ ;
  return nw ;
}
void solve()
{
  n = rd() ;
  unsigned ll sum = 0 ;
  for( int o = 1 ; o <= n ; o++ )
  {
    unsigned ll x , y ;
    x = rd() , y = rd() ;
    unsigned ll H = get(x) ;
    key[H] = x ;
    f[H] = 1 ;
    sum = sum + 1ull * o * a[H] ;
    a[H] = y ;
  }
  cout << sum ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}