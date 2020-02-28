#include<bits/stdc++.h>


using namespace std;

const int MAX = 2005;

int M[MAX][MAX];
int dp[MAX][MAX];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n; cin>>n;

   for(int i = 1 ; i <= n ; i++)
    dp[1][i] = 1, dp[i][1] = 1;
   for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
       cin>>M[i][j];
   int sol = 1;
   for(int i = 2 ; i <= n ; i++)
    for(int j = 2 ; j <= n ; j++)
     {
      if(M[i][j] != M[i - 1][j] && M[i][j] != M[i][j - 1] && M[i][j] == M[i - 1][j - 1])
        dp[i][j] = min(dp[i - 1][j - 1] , min(dp[i - 1][j] , dp[i][j - 1])) + 1;
      else
        dp[i][j] = 1;

      sol = max(sol , dp[i][j]);
     }
   cout<<sol<<"\n";
   return 0;
}
/*
7
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 0 1 0 1 1
1 1 1 0 1 1 1
1 1 0 1 0 1 1
1 1 1 1 1 1 1
*/
