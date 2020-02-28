#include<bits/stdc++.h>
#define MAXN 1005
#define MOD 1000000007
using namespace std;
typedef long long LL;

LL TP[MAXN][MAXN];
LL F[MAXN];
void pre()
{
    F[0] = 1;
    for(LL i = 1 ; i < MAXN ; i++)
    {
        F[i] = (((F[i - 1]) % MOD) * (i % MOD)) % MOD;
    }
    for(int i = 0 ; i < MAXN ; i++)
    {
        TP[i][0] = TP[i][i] = 1;
    }
for(LL i = 2 ; i < MAXN ; i++)
     for(int j = 1 ; j < i ; j++)
      TP[i][j] = (((TP[i - 1][j]) % MOD) + ((TP[i - 1][j - 1]) % MOD)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    LL n , m;
    cin>>n>>m;
    // c(n + 1 , m) * n! * m!
    LL sol = (((((TP[n + 1][m]) % MOD) * (F[n] % MOD)) % MOD) * (F[m] % MOD)) % MOD;
    cout<<sol<<"\n";

    return 0;
}
/*
0 1
1 1 1
2 1 2 1
3 1 3 3 1
4 1 4 6 4 1
5 1 5 10 10 1
6 1 6 15 20 11 1
*/

