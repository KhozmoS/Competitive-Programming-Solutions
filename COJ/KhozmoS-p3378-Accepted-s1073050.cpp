#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e5 + 5;
const int mod = 1000000007;

ll dp[MAX][2];
int n;

ll F(ll x)
{
    if(x <= 9)
        return x;

   ll sum = 0;

   while(x != 0)
   {
    sum += (x % 10);
    x /= 10;
   }
   return F(sum);
}
int main()
{
 ios_base::sync_with_stdio();cin.tie(0);
      cin>>n;
      dp[0][0] = 1;
      dp[0][1] = 1;
      for(int i = 1 ; i <= n ; i++)
      {

         ll x;cin>>x;
         x = F(x);
         for(int j = 0 ; j <= 9 ; j++)
         {
          dp[F(j + x)][i % 2] += dp[j][(i - 1) % 2];
          dp[F(j + x)][i % 2] %= mod;
         }
         for(int j = 0 ; j <= 9 ; j++)
         {
          dp[j][(i - 1) % 2] = dp[j][i % 2];
         }

      }
      for(int i = 1 ; i <= 9 ; i++)
        cout<<dp[i][n % 2]<<"\n";

    return 0;
}
