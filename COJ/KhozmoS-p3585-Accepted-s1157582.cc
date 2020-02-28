#include <bits/stdc++.h>

using namespace std;

const int MAX = 211;
typedef long long ll;
const ll mod = 1e13 + 7;
ll H1[MAX] , H2[MAX] , B = 3011;

typedef pair <ll , ll> par;
par ar[30000 * MAX];

int main()
{

  ios_base::sync_with_stdio(0);cin.tie(0);
  int n , l , alp;cin>>n>>l>>alp;
  int pos = 0;
  for(int i = 0 ; i < n ; i++)
  {
      string cad;cin>>cad;
      cad = " " + cad;
      for(int j = 1 ; j <= l ; j++)
          H1[j] = (H1[j - 1] * B + (cad[j] - '0' + 1)) % mod;

      for(int j = l ; j > 0 ; j--)
          H2[j] = (H2[j+1] * B + (cad[j] - '0' + 1)) % mod;


      for(int j = 1 ; j <= l ; j++)
          ar[pos++] = par(H1[j - 1] , H2[j+1]);
  }

  ll ans = 0;
  sort(ar , ar + pos);
  ar[pos] = par(-1 , -1);

  int piv = 0;
  for(int i = 0 ; i <= pos ; i++)
      if(ar[i] != ar[piv])
      {
          ll n = i - piv;
          ans += (n * (n - 1ll)) / 2ll;
          piv = i;
      }

  cout<<ans<<"\n";
}

