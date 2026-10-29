#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n , m ;
int son[3000005][65] ;
int cn[3000005] ;
int tot = 0 ;
map<char , int> mp ;
void insert(string s)
{
	int now = 0 ;
	for( int i = 0 ; i < s.size() ; i++ )
	{
		if(son[now][mp[s[i]]] == 0) son[now][mp[s[i]]] = ++tot ;
		now = son[now][mp[s[i]]] ;
		cn[now]++ ;
	}
}
int query(string s)
{
	int now = 0 , ans = 0 ;
	for( int i = 0 ; i < s.size() ; i++ )
	{
		if(son[now][mp[s[i]]] == 0) return 0 ;
		now = son[now][mp[s[i]]] ;
	}
	return cn[now] ;
}
void solve()
{
  cin >> n >> m ;
  for( int i = 0 ; i <= tot ; i++ )
  {
  	cn[i] = 0 ;
  	for( int j = 0 ; j <= 63 ; j++ ) son[i][j] = 0 ; 
	}
	tot = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
  	string s ;
  	cin >> s ;
  	insert(s) ;
	}
	for( int i = 1 ; i <= m ; i++ )
	{
		string s ;
		cin >> s ;
		cout << query(s) << "\n" ;
	}
}
signed main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  cin >> oT_To ;
  int cnt = 0 ;
	for( int i = 'a' ; i <= 'z' ; i++ )
	{
		mp[i] = ++cnt ;
	}
	for( int i = 'A' ; i <= 'Z' ; i++ )
	{
		mp[i] = ++cnt ;
	}
	for( int i = '0' ; i <= '9' ; i++ )
	{
		mp[i] = ++cnt ;
	}
  while(oT_To--) solve() ;
  return 0 ;
}