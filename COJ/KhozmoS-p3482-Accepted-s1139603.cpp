#include<bits/stdc++.h>


using namespace std;

const int MAX = 1005;
const int mod = 1000000007;

int dp[MAX][MAX];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n , ta , k , t;
    cin>>t;
    while(t--){
     memset(dp , 0 , sizeof(dp));
    cin>>n>>ta>>k;

    for(int i = 1 ; i <= n ; i++)
         dp[1][i] = 1ll + dp[1][i - 1];


    //cout<<query(1 , n)<<"\n";
    for(int i = 2 ; i <= ta ; i++)
      for(int j = 1 ; j <= n ; j++){
       //update(i , j , (query(i - 1 , min(n , j + k)) - query(i - 1 , max(0 , j - k - 1)) + mod) % mod);
         int l = max(j - k , 1); int r = min(n , j + k);
         dp[i][j] = (dp[i - 1][r] - dp[i - 1][l - 1] + mod) % mod;
         dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      }
     cout<<dp[ta][n]<<"\n";
    }
}

/*
11 12 22 21
1
2
i = L , long de la sub
j = n , los num del dom
k = la dif valida

i = 1
j = 1 2 3 ... n
dp[i][j] = dp[i - 1][j - k] + dp[i - 1][(j - k) + 1] + ... + dp[i - 1][j + k]
1 2
*/
// n = 5 k = 2 l = 3
// n

