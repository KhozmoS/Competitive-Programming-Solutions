#include <bits/stdc++.h>

using namespace std;

const int MAX = 2001;
int n;
bool dp[2][MAX][MAX];
int ar[25];
int tot;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 1 ; i <= n ; i++)
     cin>>ar[i] , tot += ar[i];

  dp[1][0][0] = 1;

  for(int i = 1 ; i <= n ; i++)
     for(int j = 0 ; j < MAX - 105; j++)
       for(int k = 0 ; k < MAX - 105; k++)
          if(dp[i & 1][j][k]){
            dp[(i + 1) & 1][j][k] = true;
            dp[(i + 1) & 1][j + ar[i]][k] = true;
            dp[(i + 1) & 1][j][k + ar[i]] = true;
          }
  int ans = MAX;
  for(int i = 1 ; i < MAX ; i++)
     for(int j = 1 ; j < MAX ; j++)
       if(dp[n & 1][i][j])
          ans = min(ans , max(tot - i - j , max(i , j)));

          cout<<ans<<"\n";
    return 0;
}
