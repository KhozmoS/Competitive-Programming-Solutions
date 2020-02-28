#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3 + 5;
const int mod = 1000000007;
int dp[MAX * 2][MAX];
int n;
int F(int pos , int cant , int cantx)
{
    if(pos == (2 * n))
       return 1;

    if(dp[pos][cant] != -1)
        return dp[pos][cant];

    if((pos + 1) / 2 > cant && cantx < n)
    return dp[pos][cant] = (F(pos + 1 , cant + 1 , cantx) + F(pos + 1 , cant , cantx + 1)) % mod;
    else if(cantx < n)
    return dp[pos][cant] = F(pos + 1 , cant , cantx + 1);
    else if((pos + 1) / 2 > cant)
    return dp[pos][cant] = F(pos + 1 , cant + 1 , cantx);


}
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        memset(dp , -1 , sizeof(dp));
        cin>>n;
        cout<<F(0 , 0 , 0)<<"\n";
    }

    return 0;
}
