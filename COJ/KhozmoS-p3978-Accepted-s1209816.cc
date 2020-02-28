#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back


typedef long long ll;
typedef vector <int> vi;

int n , m;
const ll mod = 1e9+7;
const int MAX = 1e4+5;

ll dp[MAX][30][30];
ll TA[30];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n>>m;
   if(n==1)
   {
        cout<<m<<"\n";
        return 0;
   }
   for(int i = 1 ; i <= m ; i++)
        for(int j = 1 ; j <= m ; j++)
           if(i!=j)
            dp[2][i][j]++;
   for(int j = 1 ; j <= m ; j++){
           TA[j] = 0;
           for(int l = 1 ; l <= m ; l++)
               TA[j] += dp[2][j][l] , TA[j] %= mod;
               }
   for(int i = 3; i <= n ; i++){
       for(int j = 1 ; j <= m ; j++)
            for(int k = 1 ; k <= m ; k++)
                if(j!=k)
                    dp[i][j][k] = (TA[k] - dp[i-1][k][j] + mod) %mod;

       for(int j = 1 ; j <= m ; j++){
           TA[j] = 0;
           for(int l = 1 ; l <= m ; l++)
               TA[j] += dp[i][j][l] , TA[j] %= mod;
               }
     }
   ll ans = 0;
   for(int i = 1 ;i <= m ; i++){
       for(int j = 1 ; j <= m ; j++)
            ans += dp[n][i][j] , ans %= mod;
       }
       cout<<ans<<"\n";
}
