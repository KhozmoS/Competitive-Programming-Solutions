#include <bits/stdc++.h>

//sol(L, K) = C (L / 2 , k) * 10^k * 10 ^ ((L / 2) - k) * 9 ^ ((L / 2) - K)

using namespace std;

typedef unsigned long long ULL;

const ULL MOD = 1e9 + 7;
const int MAXL = 1e3 + 3;

int L, K;
ULL Pow10[MAXL], Pow9[MAXL];
ULL Comb[MAXL][MAXL];

void Build()
{
    //pow10 y pow9
    Pow9[0] = 1;
    Pow10[0] = 1;
    for(int i = 1; i < MAXL; i++)
    {
        Pow9[i] = ((Pow9[i - 1] % MOD) * (9 % MOD)) % MOD;
        Pow10[i] = ((Pow10[i - 1] % MOD) * (10 % MOD)) % MOD;
    }
    //pascal triangle
    for(int i = 0; i < MAXL; i++)
        Comb[i][0] = Comb[i][i] = 1;

    for(int i = 1; i < MAXL; i++)
        for(int j = 1; j < i; j++)
            Comb[i][j] = ((Comb[i - 1][j] % MOD) + (Comb[i - 1][j - 1] % MOD)) % MOD;
}

ULL Sol(int L, int K)
{
    int a = ((Comb[L / 2][K] % MOD) * (Pow10[K] % MOD)) % MOD;
    int b = ((Pow10[(L / 2) - K] % MOD) * (Pow9[(L / 2) - K] % MOD)) % MOD;
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main()
{
    Build();

    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &L, &K);

        ULL answer;
        if(L & 1)
        {
            answer = ( (Sol(L, K - 1) % MOD) * (10 % MOD) ) % MOD;
        }
        else
            
            answer = Sol(L, K);

        printf("%llu\n", answer);
    }
    return 0;
}
