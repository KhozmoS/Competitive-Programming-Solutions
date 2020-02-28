#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll n;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>n)
    {
      n--;
      if(n % 4 == 0)
      {
        ll nn = n / 4;
        cout<<((((((nn % mod) * ((n + 1) % mod)) % mod) * ((n + 2) % mod)) % mod) * ((n + 3) % mod)) % mod;
      }
      else if((n + 1) % 4 == 0)
      {
         ll nn = (n + 1) / 4;
        cout<<((((((n % mod) * ((nn) % mod)) % mod) * ((n + 2) % mod)) % mod) * ((n + 3) % mod)) % mod;
      }
      else if((n + 2) % 4 == 0)
      {
       ll nn = (n + 2) / 4;
        cout<<((((((n % mod) * ((n + 1) % mod)) % mod) * ((nn) % mod)) % mod) * ((n + 3) % mod)) % mod;
      }
      else
      {
       ll nn = (n + 3) / 4;
        cout<<((((((n % mod) * ((n + 1) % mod)) % mod) * ((n + 2) % mod)) % mod) * ((nn) % mod)) % mod;
      }
      cout<<"\n";
    }

    return 0;
}
