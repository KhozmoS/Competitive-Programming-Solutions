#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3 + 5;
const int mod = 1000000007;
int dp[MAX][MAX];
int n;
int F(int a , int b)
{
 if(b > a || b < 0) return 0;

 if(dp[a][b] != -1) return dp[a][b];

 return dp[a][b] = (F(a - 1 , b) + F(a , b - 1)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        memset(dp , -1 , sizeof(dp));
        dp[0][0] = 1;
        cin>>n;
        cout<<F(n , n)<<"\n";
    }

    return 0;
}
