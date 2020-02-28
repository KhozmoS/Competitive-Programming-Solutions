#include <bits/stdc++.h>

using namespace std;
//int n , m;
const int mod = 1000000009;
const int MAXN = 111;
typedef long long ll;
ll dp[MAXN][25][MAXN];

ll ar[MAXN];
//int cont;
ll r , t , n;

ll F(int pos , ll sum ,  int cont)
{
    if(t == cont)
    return (sum % r == 0);

    if(pos == n)
        return 0;
    if(dp[pos][sum][cont] != -1)
      return dp[pos][sum][cont];

    return dp[pos][sum][cont] = (F(pos + 1 , sum , cont) + F(pos + 1 , (sum + ar[pos]) % r , cont + 1)) % mod;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>t>>r;
      memset(dp , -1 , sizeof(dp));

      for(int i = 0 ; i < n ; i++) cin>>ar[i];

      cout<<F(0 , 0 , 0)<<"\n";
    return 0;
}
