#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 55;
int dp[MAX][MAX][MAX*2][2];
int n , m , ar[MAX][MAX] , c;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
   while(t--){
   for(int i = 0 ; i < MAX ; i ++)
       for(int j = 0 ; j < MAX ; j++)
           for(int k = 0 ; k < MAX*2 ; k++)
               for(int l = 0 ; l < 2 ; l++)
                   dp[i][j][k][l] = -1;

   cin>>n>>m>>c;
   for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= m ; j++)
           cin>>ar[i][j];

   dp[1][1][0][0] = ar[1][1];
   dp[1][1][0][1] = ar[1][1];

   for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= m ; j++)
           for(int k = 0 ; k <= c ; k++)
               for(int l = 0 ; l < 2 ; l++)
                   if(!k && !l && dp[i][j-1][0][l] != -1)
                        dp[i][j][k][l] = max(dp[i][j][k][l] , ar[i][j] + dp[i][j-1][0][l]);
                   else if(!k && l && dp[i-1][j][0][l] != -1)
                        dp[i][j][k][l] = max(dp[i][j][k][l] , ar[i][j] + dp[i-1][j][0][l]);
                   else if(k && !l && (dp[i][j-1][k][l] != -1 || dp[i][j-1][k-1][1] != -1))
                        dp[i][j][k][l] = max(dp[i][j][k][l] , max(dp[i][j-1][k][l] + ar[i][j] , dp[i][j-1][k-1][1] + ar[i][j]));
                   else if(k && l && (dp[i-1][j][k][l] != -1 || dp[i-1][j][k-1][0] != -1))
                        dp[i][j][k][l] = max(dp[i][j][k][l] , max(dp[i-1][j][k][l] + ar[i][j] , dp[i-1][j][k-1][0] + ar[i][j]));
   int ans = -1;
   for(int i = 0 ; i <= c ; i++)
       ans = max(ans , max(dp[n][m][i][1] , dp[n][m][i][0]));
   //cout<<dp[n][m][0][0]<<" "<<dp[n][m][0][1]<<"\n";
   cout<<ans<<"\n";
   }

}
