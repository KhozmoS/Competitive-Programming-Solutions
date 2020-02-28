#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;

int dp[MAXN];
int ar[MAXN];
int ta[MAXN];

int n , k , t;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>t;
    while(t--){
     cin>>n>>k;
     memset(dp , 0 , sizeof(dp));
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>ar[i];
        if(ar[i] < 0)
            ar[i] *= -1;
        ta[i] = 0;
        ta[i] = (ar[i] + ta[i - 1]) % k;
      //  dp[ta[i]] = 0;
        dp[ta[i]]++;
    }
      long long sol = 0;
      for(int i = n ; i > 0 ; i--)
       {
         if(!ta[i]) sol++;

         dp[ta[i]]--;
         sol += dp[ta[i]];
       }

       cout<<sol<<"\n";
    }
    return 0;
}
