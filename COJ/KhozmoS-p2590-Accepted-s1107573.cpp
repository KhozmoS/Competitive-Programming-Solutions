#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e5 + 5;
const ll mod = 5000000;
ll ab[MAX][55];
int ar[MAX];
void update(int pos , int c , ll v)
{
    for(int i = pos ; i < MAX ; i += (i & -i)){
        ab[i][c] += v;
        ab[i][c] %= mod;
    }
}
ll query(int pos , int c)
{
   ll ret = 0;

   for(int i = pos ; i > 0 ; i -= (i & -i)){
    ret += ab[i][c];
    ret %= mod;
   }

   return ret;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n , k;
  cin>>n>>k;

  for(int i = 0 ; i < n ; i++)
  {
      cin>>ar[i];
      ar[i]++;
  }
  update(1 , 0 , 1ll);
  for(int i = 0 ; i < n ; i++)
  for(int j = 1 ; j <= k ; j++)
    update(ar[i] , j , query(ar[i] - 1 , j - 1));

  cout<<query(MAX - 2 , k)<<"\n";
    return 0;
}
