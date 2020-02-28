#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int MAX = 1e6 + 5;
ll dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 3;

    for(ll i = 4 ; i < MAX ; i++)
        dp[i] = (((i - 1) * dp[i - 1]) % mod) + (((i - 2) * dp[i - 2]) % mod) , dp[i] %= mod;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
