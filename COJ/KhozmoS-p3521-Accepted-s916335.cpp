#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
/*LL POW (LL b , LL e)
{
   if(e == 0)
    return 0;
   if(e % 2 == 0)
    {
     LL r = POW(b , e / 2);
     return ((r % MOD) * (r % MOD)) % MOD;
    }
    return ((b % MOD) * (POW(b , e - 1) % MOD)) % MOD;
}*/
LL n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n)
    {
        n --;
        if(n % 3 == 0)
        {
          LL nn = n / 3;
          cout<<((( nn % MOD) * ((n + 1) % MOD) % MOD) * ((n + 2) % MOD)) % MOD<<"\n";
        }
        else if((n + 1) % 3 == 0)
        {
            LL nn = (n + 1) / 3;
            cout<<(( (n  % MOD) * ((nn) % MOD) % MOD) * ((n + 2) % MOD)) % MOD<<"\n";
        }
        else
        {
            LL nn = ( n + 2 ) / 3;
            cout<<((( n % MOD) * ((n + 1) % MOD) % MOD) * ((nn) % MOD)) % MOD<<"\n";
        }
    }

    return 0;
}
