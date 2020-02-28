#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 5005;

string cad , cad1;
int dp[MAX][MAX];

int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  cin>>n;
  cin>>cad1;
  cad = cad1;
  reverse(cad1.begin() , cad1.end());
  cad1 = " " + cad1;
  cad = " " + cad;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
      if(cad[i] == cad1[j])
       dp[i][j] = dp[i - 1][j - 1] + 1;
      else
       dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

      cout<<n - dp[n][n]<<"\n";
}
