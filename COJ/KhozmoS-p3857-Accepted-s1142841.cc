#include <bits/stdc++.h>

using namespace std;

// 2 1 4 3    5
const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
ll dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[2] = 1;

    for(ll i = 3 ; i < MAX ; i++)
    {
        dp[i] = (i - 1) * dp[i - 1];
        dp[i] %= mod;
        dp[i] += (i - 1) * dp[i - 2];
        dp[i] %= mod;
    }
    int t , n;cin>>t;

    while(t--)
          cin>>n , cout<<dp[n]<<"\n";

}
