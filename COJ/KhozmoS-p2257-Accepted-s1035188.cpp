#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int MAXN = 1005;

int dp[MAXN][MAXN];
int ta[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

   for(int i = 1 ; i < MAXN ; i++)
   for(int j = 1 ; j < MAXN ; j++)
   {
     dp[i][j] = (1 + ta[i - 1][j]) % mod;
     ta[i][j] = (ta[i][j - 1] + dp[i][j]) % mod;
   }

  int t;
   cin>>t;
   while(t--)
   {
     int n , k;
     cin>>k>>n;
     cout<<dp[n][k]<<"\n";
   }
 return 0;
}
