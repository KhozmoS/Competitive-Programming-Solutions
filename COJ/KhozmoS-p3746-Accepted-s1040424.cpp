#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
typedef long long ll;


ll dp[MAXN];

ll b[4];
//int n;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    int n;

    ll sol = 1111111111;
    cin>>n>>b[0]>>b[1]>>b[2];

      dp[0] = 1;
      //int pos;
      for(int i = 1 ; i < MAXN ; i++) dp[i] = 1111111111;

    for(int i = 0 ; i < 3 ; i++)
    {
      for(int j = i + 1 ; j < MAXN ; j++)
      {
          if(dp[j - (i + 1)])
          {
            dp[j] = min(dp[j - (i + 1)] + b[i] , dp[j]);
            //dp[j]--;
            if((n + j) % 4 == 0){
            if(sol > dp[j]){
            sol = dp[j];
           // pos = j;
            }
            }
          }
      }
    }
    if(n % 4 == 0)
    cout<<0<<"\n";
    else
    cout<<--sol<<"\n";

    return 0;
}
