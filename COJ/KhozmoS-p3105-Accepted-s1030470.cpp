#include <bits/stdc++.h>

using namespace std;
 typedef long long LL;

 const LL MAXN = 1000005;
 const LL MOD = 1000000007;

 LL hole[MAXN];
 LL sol[MAXN];

 LL L , t , s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>L>>t>>s;
    if(t > s) swap(t , s);

    hole[0] = 1;
    for(int i = t ; i < s ; i++)
    hole[i] = hole[i - t] % MOD;

    for(int i = s ; i <= L ; i++)
     {
        hole[i] = hole[i - t] % MOD;
        hole[i] = (hole[i] + hole[i - s]) % MOD;
     }
     cout<<hole[L]<<"\n";
   return 0;
}
