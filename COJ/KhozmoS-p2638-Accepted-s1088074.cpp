#include <bits/stdc++.h>

using namespace std;
const int MAX = 3e3 + 5;
const int mod = 100999;
int t , n , dp[MAX];


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   dp[0] = 1;
   for(int i = 1 ; i <= 2000 ; i++)
       for(int j = 2000 - i ; j >= 0 ; j--)
          if(dp[j])
          dp[j + i] = (dp[j] + dp[j + i]) % mod;
   cin>>t;
   while(t--)
     cin>>n , cout<<dp[n]<<"\n";
   return 0;
}
