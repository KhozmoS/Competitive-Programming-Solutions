#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111;

string cad , c;
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
      cin>>cad>>c;
      dp[0] = 1;
      int ta = cad.size();
      int tb = c.size();
      for(int i = 0 ; i < ta ; i++)
      {
       for(int j = tb - 1 ; j >= 0 ; j--)
       {
         if(cad[i] == c[j])
          dp[j + 1] += dp[j];
       }
      }
      cout<<dp[tb]<<"\n";
      memset(dp , 0 , sizeof(dp));
    }

    return 0;
}
/*
apasiapa
apa
*/
