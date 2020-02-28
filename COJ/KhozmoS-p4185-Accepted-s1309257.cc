#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6+5;

long long dp[MAX];

int main()
{
    int n;scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%lld" , &dp[i]);
        if(i==1) continue;
        dp[i] = max(dp[i-1] , dp[i-2]+dp[i]);
    }
    printf("%lld\n" , dp[n]);

}
