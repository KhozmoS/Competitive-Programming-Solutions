#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e4 + 5;
ll a , b , n , mod;
ll dp[MAX];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>a>>b>>mod;
   dp[0] = 1ll;
   for(ll i = a ; i <= b ; i++)
     for(ll j = i ; j <= n ; j++)
       dp[j] = (dp[j] + dp[j - i]) % mod;

   cout<<dp[n]<<"\n";
}
