#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int n , q ;
struct cTr
{
  int res ;
  struct node
  {
    ll cnt , len ;
    int lson , rson ;
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 6) ;
  }
  void push_up(int k , int l , int r)
  {
    if(c[k].cnt) c[k].len = r - l + 1 ;
    else if(l == r) c[k].len = 0 ;
    else
    {
      c[k].len = c[c[k].lson].len + c[c[k].rson].len ;
    }
  }
  void update(int &k , int l , int r , int L , int R , ll add)
  {
    if(!k) k = ++res ;
    if(L <= l && r <= R)
    {
      c[k].cnt += add ;
      push_up(k , l , r) ;
      return ;
    }
    int mid = l + r >> 1 ;
    if(L <= mid) update(c[k].lson , l , mid , L , R , add) ;
    if(R > mid) update(c[k].rson , mid + 1 , r , L , R , add) ;
    push_up(k , l , r) ;
  }
};
cTr Tr ;
struct node
{
  int x , l , r , d ;
  bool operator < (const node &a)
  {
    return x < a.x ;
  }
};
void solve()
{
  cin >> n ;
  vector<node> ve ;
  int minY = 1e9 , maxY = 0 ;
  for( int i = 1 ; i <= n ; i++ )
  {
    int x1 , y1 , x2 , y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    if(x1 == x2 || y1 == y2) continue ;
    minY = min(minY , y1) ;
    maxY = max(maxY , y2 - 1) ;
    ve.push_back({x1 , y1 , y2 - 1 , 1}) ;
    ve.push_back({x2 , y1 , y2 - 1 , -1}) ;
  }
  sort(ve.begin() , ve.end()) ;
  int root = 0 ;
  int i = 0 ;
  ll ans = 0 ;
  int lst = ve[0].x ;
  while(i < ve.size())
  {
    ll x = ve[i].x ;
    ans += 1ll * Tr.c[root].len * (x - lst) ;
    while(i < ve.size() && ve[i].x == x)
    {
      Tr.update(root , minY , maxY , ve[i].l , ve[i].r , ve[i].d) ;
      i++ ;
    }
    lst = x ;
  }
  cout << ans << "\n" ;
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}