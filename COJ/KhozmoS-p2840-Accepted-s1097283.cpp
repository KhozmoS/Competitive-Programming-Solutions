#include <bits/stdc++.h>

using namespace std;

int n, k, dp[1600];

int main() {
    scanf("%d", &n);

    dp[0] = 1;
    k = n * (n + 1) / 2;
    for(int i = 1; i <= n; i++)
        for(int j = k; j >= i; j--)
            dp[j] += dp[j - i];
            
    cout<<dp[k / 2] / 2<<"\n";
    //printf("%d\n", dp[k / 2] / 2);
}
