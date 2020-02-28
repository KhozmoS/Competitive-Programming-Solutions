#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e4;
const int MAX = 1e6 + 5;
int n , u , q;
int ab[MAX];

void update(int pos , int v)
{
    if(pos == 0) return;

    for(int i = pos ; i < MAX ; i += (i & -i))
        ab[i] = (ab[i] + v) % mod;
}

int query(int pos)
{
    int sum = 0;
    for(int i = pos ; i > 0 ; i -= (i & -i))
       sum = (sum + ab[i]) % mod;

    return sum;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>u>>q;
  u += q;
  while(u--)
  {
      int typ; cin>>typ;
      if(typ == 1)
      {
          int i , k;
          cin>>i>>k;
          update(i , k * 2);
          update(i - 1 , k);
          update(i + 1 , k);
      }
      else
      {
          int i , j;
          cin>>i>>j;

          cout<<(query(j) - query(i - 1) + mod) % mod<<"\n";
      }
  }
    return 0;
}
