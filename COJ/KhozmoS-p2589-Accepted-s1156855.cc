#include <bits/stdc++.h>

using namespace std;
const int MAX = (1<<18);
typedef long long ll;

char num[20];
ll dp[17][(1<<18)];
int n , ar[20] , k;
ll F(int c , int last , int mask)
{
    if(mask >= (1<<18)) return 0;
    if(c == n) return 1ll;

    if(dp[mask][last] != -1) return dp[mask][last];
    ll res = 0;
    for(int i = 0 ; i < n ; i++)
        if(!(mask & 1 << i) && abs(ar[last] - ar[i]) > k)
           res += F(c + 1 , i , (mask | (1 << i)));

    return dp[last][mask] = res;
}

int main()
{

   scanf("%d%d" , &n,&k);
   for(int i = 0 ; i < n ; i++) {scanf("%d" , &ar[i]); dp[i][(1<<i)]++;}


   for(int mask = 1 ; mask < (1<<n) ; mask++)
      for(int last = 0 ; last < n ; last++)
        for(int i = 0 ; i <  n ;i++)
           if(!(mask & (1 << i)) && abs(ar[last] - ar[i]) > k){
                 dp[i][mask | (1<<i)] += dp[last][mask];
               //  cout<<dp[i][mask | (1<<i)]<<" "<<(mask | (1<<i))<<" "<<i<<"\n";
           }

   ll ans = 0;
  // cout<<(1<<n)-1<<"\n";
   for(int i = 0 ; i < n ; i++)
      ans += dp[i][(1<<n)-1];
 // cout<<n<<" "<<k<<"\n";
   printf("%lld\n" , ans);
}
