#include <bits/stdc++.h>

using namespace std;


const int mod = 1e9 + 7;

string S , pot[35];
int dp[35];

string to_s(long long x)
{
    string res = "";
    while(x != 0)
    {
        res = char(x % 10 + 48) + res;
        x /= 10;
    }
    return res;
}
void crear()
{
    long long m = 1;

    for(int i = 1 ; i <= 33 ; i++)
    {
        pot[i] = to_s(m);
        m *= 2;
    }
}
int main()
{

   crear();
   //for(int i = 1 ; i <= 32 ; i++) cout<<pot[i]<<"\n";
    cin>>S;

    int ans = 0;
    int ta = S.size();
    for(int i = 1; i <= 33 ; i++)
    {
        dp[0] = 1;
        for(int j = 0 ; j < ta ; j++)
        {
         for(int k = pot[i].size() - 1 ; k >= 0 ; k--)
             if(pot[i][k] == S[j])
              dp[k + 1] = (dp[k + 1] + dp[k]) % mod;
        }
        ans = (ans + dp[pot[i].size()]) % mod;
        memset(dp , 0 , sizeof(dp));
    }
    cout<<ans<<"\n";
}
//1642178



