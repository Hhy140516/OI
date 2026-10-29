#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e5 + 5 ;
int n , q , mod ;
ll a[kMaxN] ;
struct cTr
{
  struct node
  {
    ll sum , lazya , lazym ;
    node()
    {
      lazym = 1 ;
    }
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 2) ;
  }
  inline int lson(int k)
  {
    return k << 1 ;
  }
  inline int rson(int k)
  {
    return k << 1 | 1 ;
  }
  friend node operator + (const node &a , const node &b)
  {
    node c ;
    c.sum = a.sum + b.sum ;
    return c ;
  }
  void push_up(int k)
  {
    c[k] = c[lson(k)] + c[rson(k)] ;
  }
  void push_down(int k , int l , int r)
  {
    if(c[k].lazya != 0 || c[k].lazym != 1)
    {
      int mid = l + r >> 1 ;
      c[lson(k)].sum = (c[lson(k)].sum * c[k].lazym % mod + c[k].lazya * (mid - l + 1) % mod) % mod ;
      c[lson(k)].lazym = c[lson(k)].lazym * c[k].lazym % mod ;
      c[lson(k)].lazya = (c[lson(k)].lazya * c[k].lazym % mod + c[k].lazya) % mod ; 
      c[rson(k)].sum = (c[rson(k)].sum * c[k].lazym % mod + c[k].lazya * (r - mid) % mod) % mod ;
      c[rson(k)].lazym = c[rson(k)].lazym * c[k].lazym % mod ;
      c[rson(k)].lazya = (c[rson(k)].lazya * c[k].lazym % mod + c[k].lazya) % mod ; 
      c[k].lazym = 1 , c[k].lazya = 0 ;
    }
  }
  void build(int k , int l , int r)
  {
    if(l == r)
    {
      c[k].sum = a[l] ;
      return ;
    }
    int mid = l + r >> 1 ;
    build(lson(k) , l , mid) ;
    build(rson(k) , mid + 1 , r) ;
    push_up(k) ;
  }
  void update(int k , int l , int r , int L , int R , ll mul , ll add)
  {
    if(L <= l && r <= R)
    {
      c[k].sum = (c[k].sum * mul % mod + (r - l + 1) * add % mod) % mod ;
      c[k].lazym = c[k].lazym * mul % mod ;
      c[k].lazya = (c[k].lazya * mul % mod + add) % mod ;
      return ;
    }
    push_down(k , l , r) ;
    int mid = l + r >> 1 ;
    if(L <= mid) update(lson(k) , l , mid , L , R , mul , add) ;
    if(R > mid) update(rson(k) , mid + 1 , r , L , R , mul , add) ;
    push_up(k) ;
  }
  ll query(int k , int l , int r , int L , int R)
  {
    if(L <= l && r <= R)
    {
      return c[k].sum ;
    }
    push_down(k , l , r) ;
    int mid = l + r >> 1 ;
    ll sum = 0 ;
    if(L <= mid) sum = (sum + query(lson(k) , l , mid , L , R)) % mod ;
    if(R > mid) sum = (sum + query(rson(k) , mid + 1 , r , L , R)) % mod ;
    return sum ;
  }
};
cTr Tr ;
void solve()
{
 cin >> n >> q >> mod ;
 for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
 Tr.build(1 , 1 , n) ;
 while(q--)
 {
  int opt ;
  cin >> opt ;
  if(opt == 1)
  {
    int x , y ;
    ll k ;
    cin >> x >> y >> k ;
    Tr.update(1 , 1 , n , x , y , k , 0) ;
  }
  else if(opt == 2)
  {
    int x , y ;
    ll k ;
    cin >> x >> y >> k ;
    Tr.update(1 , 1 , n , x , y , 1 , k) ;
  }
  else
  {
    int l , r ;
    cin >> l >> r ;
    cout << Tr.query(1 , 1 , n , l , r) << "\n" ;
  }
 }
}
int main()
{
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
  int oT_To = 1 ;
  // cin >> oT_To ;
  while(oT_To--) solve() ;
  return 0 ;
}