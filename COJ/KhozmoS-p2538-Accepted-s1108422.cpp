#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9;
const int MAX = 1e3 + 5;

ll dp[MAX][3] ,  ar[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++) cin>>ar[i];
    dp[0][0] = 1;

    for(int i = 1 ; i <= n ; i++)
      for(int j = 0 ; j < 3 ; j++)
       {
         for(int k = i - 1 ; k >= 0 ; k--){
         dp[i][((ar[i] % 3) + j) % 3] += dp[k][j];
         dp[i][((ar[i] % 3) + j) % 3] %= mod;
         }
       }
       ll ans = 0;
       for(int i = 1 ; i <= n ; i++)
        ans = (dp[i][0] + ans) % mod;
    cout<<ans<<"\n";
    return 0;
}
