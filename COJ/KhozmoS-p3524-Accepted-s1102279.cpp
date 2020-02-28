#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll N , K;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   while(cin>>N>>K)
   {
       ll ans = 1;
       N--;
       for(ll n = N ; n <= N + K + 1 ; n++)
       {
           ll m;
           if(n % (K + 2) == 0) m = n / (K + 2);
           else m = n;

           ans = ((ans % mod) * (m % mod)) % mod;
       }
       cout<<ans<<"\n";
   }

    return 0;
}
