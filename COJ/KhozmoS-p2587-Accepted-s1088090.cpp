#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const huge MAXN = 2007;
const huge MOD = 1e9 + 7;

huge TP[MAXN][MAXN];
huge fact[MAXN], dp[MAXN];

void build()
{
    for(int i = 0; i < MAXN; i++)
        TP[i][0] = TP[i][i] = 1;

    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j <= i; j++)
            TP[i][j] = (TP[i - 1][j] + TP[i - 1][j - 1]) % MOD;

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}


int main()
{
    build();

    huge N;
    cin >> N;

    dp[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        huge x = 0;
        for(int j = 1; j <= i; j++)
            x = (x + TP[i][j] * dp[i - j]) % MOD;
        dp[i] = (fact[i] - x + MOD) % MOD;
    }
    cout << dp[N] << endl;


    return 0;
}
