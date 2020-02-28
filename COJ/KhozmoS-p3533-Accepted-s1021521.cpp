#include <bits/stdc++.h>

using namespace std;

int N;
int ar[1111111];
int dp[1111111];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;

    for(int i = 0 ; i < N ; i++) cin>>ar[i];

    dp[0] = ar[0];
    dp[1] = max(dp[0] , ar[1]);
    for(int i = 2 ; i < N ; i++)
    {
        dp[i] = max(ar[i] + dp[i - 2] , dp[i - 1]);
    }
    cout<<dp[N - 1]<<"\n";

    return 0;
}
