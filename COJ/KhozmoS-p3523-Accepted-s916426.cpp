#include<bits/stdc++.h>
#define MOD 998244353

using namespace std;
typedef long long LL;
LL n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   while(cin>>n)
   {
       n--;
     if(n % 4 == 0)
     {
       LL nn = n / 4;
       cout<<(((((nn % MOD) * ((n + 1) % MOD)) % MOD) % MOD) * (((( n + 2 ) % MOD) * ((n + 3) % MOD)) % MOD ) % MOD) % MOD<<"\n";
     }
     else if((n + 1) % 4 == 0)
     {
         LL nn = (n + 1) / 4;
       cout<<((((((n) % MOD) * ((nn) % MOD)) % MOD) % MOD) * ((((n + 2 ) % MOD) * ((n + 3) % MOD)) % MOD ) % MOD) % MOD<<"\n";
     }
     else if((n + 2) % 4 == 0)
     {
       LL nn = (n + 2) / 4;
       cout<<((((((n) % MOD) * ((n + 1) % MOD)) % MOD) % MOD) * ((((nn) % MOD) * ((n + 3) % MOD)) % MOD ) % MOD) % MOD<<"\n";
     }
     else{
       LL nn = (n + 3) / 4;
         cout<<((((((n) % MOD) * ((n + 1) % MOD)) % MOD) % MOD) * ((((n + 2 ) % MOD) * ((nn) % MOD)) % MOD ) % MOD) % MOD<<"\n";
     }
   }

    return 0;
}
//(n * (n + 1) * (n + 2) * (n + 3)) / 4
