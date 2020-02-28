#include <bits/stdc++.h>

using namespace std;

long long dp[4];

int main()
{
    string cad;
    cin >> cad;

    dp[0] = 1;
    long long sol = 0, sum = 0;
    for(int i = 0; i < cad.size(); i++)
    {
         if(cad[i] < '0' || cad[i] > '9')
         {
             dp[0] = 1;
             dp[1] = dp[2] = 0;
             sum = 0;
         }
         else
         {
             sum = (cad[i] - '0' + sum) % 3;
             sol += dp[sum];
             dp[sum]++;
         }
    }
    cout << sol << "\n";

    return 0;
}
