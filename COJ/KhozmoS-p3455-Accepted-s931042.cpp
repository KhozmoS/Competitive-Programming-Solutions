#include <bits/stdc++.h>

using namespace std;
 string cad;
 int dp[4];
 int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>t;
      while(t--)
      {
          dp[1] = dp[2] = dp[3] = 0;
          cin>>cad;
          int ta = cad.size();
          for(int i = 0 ; i < ta ; i++)
          {
              if(cad[i] == 'C') dp[1]++;
              if(cad[i] == 'A') dp[2] += dp[1];
              if(cad[i] == 'T') dp[3] += dp[2];
          }
          cout<<dp[3]<<"\n";
      }

    return 0;
}
