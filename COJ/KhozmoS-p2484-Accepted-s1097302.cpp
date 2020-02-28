#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1000000007;
int dp[2502];
int ms[2502] , m , n;



int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
   ms[0] = m;
   for(int i = 1 ; i <= n ; i++) cin>>ms[i] , ms[i] += ms[i - 1];

   for(int i = 0 ; i <= n ; i++) dp[i] = inf;
    //cout<<ms[1]<<"\n";
   for(int i = 1 ; i <= n ; i++)
     for(int j = i ; j ; j--)
       if(!(i - j)) dp[i] = min(ms[j] , dp[i]);
       else dp[i] = min(dp[i - j] + ms[j] + m , dp[i]);

   cout<<dp[n]<<"\n";
}
