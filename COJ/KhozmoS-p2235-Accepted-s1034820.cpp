#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;

//int dp[10000007][4];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   ll a = 1; ll b = 1; ll c = 1; ll d = 0;
   int n; cin>>n;
   for(int i = 1 ; i < n ; i++)
   {
     ll a1 = a; ll b1 = b; ll c1 = c; ll d1 = d;
     a = (b1 + c1 + d1) % MOD;
     b = (a1 + c1 + d1) % MOD;
     c = (a1 + b1 + d1) % MOD;
     d = (a1 + b1 + c1) % MOD;
   }
   cout<<d<<"\n";
    return 0;
}
