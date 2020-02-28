#include <bits/stdc++.h>

using namespace std;


const int mod =  1000000007;
const int MAX = 1e7 + 5;
int dp[MAX];

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
  int t , k;
  cin>>t>>k;
  for(int i = 1 ; i < k ; i++)
     dp[i] = 1;
     dp[k] = k - 1;

  for(int i = k + 1 ; i < MAX ; i++)
    dp[i] = ((dp[i - 1] + dp[i - 1]) % mod - dp[i - k - 1] + mod) % mod;

  while(t--)
  {
    int n;
    cin>>n;
   
    cout<<dp[n]<<"\n";
  }
  return 0;
}
