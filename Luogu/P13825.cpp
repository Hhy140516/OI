#include<bits/stdc++.h>
using namespace std ;
#define ll unsigned long long
const int kMaxN = 1e5 + 5 ;
int n , q ;
struct cTr
{
  int res ;
  struct node
  {
    ll sum , lazy ;
    int lson , rson ;
  };
  vector<node> c ;
  cTr()
  {
    c.resize(kMaxN << 6) ;
  }
  inline int lson(int k)
  {
    return k << 1 ;
  }
  inline int rson(int k)
  {
    return k << 1 | 1 ;
  }
  void push_up(int k)
  {
    c[k].sum = c[c[k].lson].sum + c[c[k].rson].sum ;
  }
  void push_down(int k , int l , int r)
  {
    if(c[k].lazy)
    {
      int mid = l + r >> 1 ;
      if(!c[k].lson) c[k].lson = ++res ;
      c[c[k].lson].sum += (mid - l + 1) * c[k].lazy ;
      c[c[k].lson].lazy += c[k].lazy ;
      if(!c[k].rson) c[k].rson = ++res ;
      c[c[k].rson].sum += (r - mid) * c[k].lazy ;
      c[c[k].rson].lazy += c[k].lazy ;
      c[k].lazy = 0 ;
    }
  }
  void update(int &k , int l , int r , int L , int R , ll add)
  {
    if(!k) k = ++res ;
    if(L <= l && r <= R)
    {
      c[k].sum += (r - l + 1) * add ;
      c[k].lazy += add ;
      return ;
    }
    push_down(k , l , r) ;
    int mid = l + r >> 1 ;
    if(L <= mid) update(c[k].lson , l , mid , L , R , add) ;
    if(R > mid) update(c[k].rson , mid + 1 , r , L , R , add) ;
    push_up(k) ;
  }
  ll query(int k , int l , int r , int L , int R)
  {
    if(!k) return 0 ;
    if(L <= l && r <= R)
    {
      return c[k].sum ;
    }
    push_down(k , l , r) ;
    int mid = l + r >> 1 ;
    ll sum = 0 ;
    if(L <= mid) sum = sum + query(c[k].lson , l , mid , L , R) ;
    if(R > mid) sum = sum + query(c[k].rson , mid + 1 , r , L , R) ;
    return sum ;
  }
};
cTr Tr ;
void solve()
{
 cin >> n >> q ;
 int root = 0 ;
 while(q--)
 {
  int opt ;
  cin >> opt ;
  if(opt == 1)
  {
    int x , y ;
    ll k ;
    cin >> x >> y >> k ;
    Tr.update(root , 1 , n , x , y , k) ;
  }
  else
  {
    int l , r ;
    cin >> l >> r ;
    cout << Tr.query(root , 1 , n , l , r) + 1ll * (l + r) * (r - l + 1) / 2 << "\n" ;
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