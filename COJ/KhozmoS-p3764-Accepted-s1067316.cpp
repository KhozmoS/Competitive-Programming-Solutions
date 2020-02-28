#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1111;
const int mod = 1000000007;

typedef long long ll;

ll P[MAXN][MAXN];

void PASCAL()
{
  P[0][0] = 1;

  for(int i = 1 ; i < MAXN ; i++)
   for(int j = 1 ; j <= i ; j++)
    P[i][j] = ((P[i - 1][j - 1] % mod) + (P[i - 1][j] % mod)) % mod;
}
ll fact(ll n)
{
 ll f = 1;
 for(ll i = 1 ; i <= n ; i++)
 f = ((f % mod) * (i % mod)) % mod;
 return f;
}

ll N , M;

int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);
   PASCAL();
 //cout<<P[6][3];
    cin>>N>>M;
     /*if(M == 2)
     {
      cout<<fact(N + 2)<<"\n";
      return 0;
     }*/
     ll FN = fact(N);
     ll FM = fact(M);

    ll E = N + 1;
     ll r = ((FN % mod) * (FM % mod)) % mod;
     ll sol = ((r % mod) * (P[E + 1][M + 1] % mod)) % mod;
     M--;
     // ll FN = fact(N);
      FM = fact(M);
     r = ((FN % mod) * (FM % mod)) % mod;
     ll s = ((r % mod) * (P[E + 1][M + 1] % mod)) % mod;
     s *= 2;
     cout<<((sol % mod) + (s % mod)) % mod;
    return 0;
}
