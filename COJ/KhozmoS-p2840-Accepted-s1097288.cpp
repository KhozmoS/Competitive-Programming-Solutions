#include<bits/stdc++.h>

using namespace std;

int dp[36 * 36] , n;


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   int top = (n * (n + 1)) / 2;
   dp[0] = 1;
      for(int i = 1 ; i <= n ; i++)
          for(int j = top ; j >= i ; j--)
             dp[j] += dp[j - i];

      cout<<dp[top / 2] / 2<<"\n";
}
