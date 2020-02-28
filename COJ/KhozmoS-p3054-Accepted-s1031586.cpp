#include<bits/stdc++.h>

using namespace std;
const int MOD = 1000003;

typedef long long ll;
const int MAXN = 1000005;

ll dp[MAXN];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i<= 1000000; i++)
    {
        dp[i] = (i*(dp[i-1])%MOD + 1)%MOD;
    }
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}
