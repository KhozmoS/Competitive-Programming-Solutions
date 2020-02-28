#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;


int dp[MAXN];
int ar[MAXN];

int N;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i = 0 ; i < N ; i++)
    cin>>ar[i];

    for(int i = N - 1 ; i >= 0 ; i--)
    dp[i] = max(dp[i + 2] + ar[i] , dp[i + 1]);

    cout<<dp[0]<<"\n";
    return 0;
}