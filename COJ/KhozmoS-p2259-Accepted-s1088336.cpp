#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;
const int mod = 1e9 + 7;
int dp[MAX * 2][MAX] , n;

int F(int pos , int c1 , int c2)
{
    if ((n - pos) < (c1 - c2) || c1 < c2)
        return 0;

    if(pos == n) return 1;

    if(dp[pos][c1 - c2] != -1) return dp[pos][c1 - c2];

    return dp[pos][c1 - c2] = (F(pos + 1 , c1 + 1 , c2) + F(pos + 1 , c1 , c2 + 1)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp , -1 , sizeof(dp));
        cin>>n;
        n *= 2;
        cout<<F(0 , 0 , 0)<<"\n";
    }

    return 0;
}
