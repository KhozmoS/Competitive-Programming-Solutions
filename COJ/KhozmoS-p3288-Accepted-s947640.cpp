#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
const int MOD = 1000007;

typedef long long LL;
int PASCAL[MAXN][MAXN];
int TA[MAXN];
void tabla()
{
    PASCAL[0][0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        LL sum = 0;
    for(int j = 1 ; j <= i ; j++)
    {
        PASCAL[i][j] = ((PASCAL[i - 1][j - 1] % MOD) + (PASCAL[i - 1][j] % MOD)) % MOD;
        sum = ((sum % MOD) + (PASCAL[i][j] % MOD)) % MOD;
    }
    TA[i] = ((TA[i - 1] % MOD) + (sum % MOD)) % MOD;
    }
}
int n , m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    tabla();
    /*for(int i = 0 ; i < 11 ; i++){
    for(int j = 0 ; j <= i ; j++)
        cout<<PASCAL[i][j]<<" ";
        cout<<endl;
    }*/
    while(true)
    {
        cin>>n>>m;
        if(n < 0 && m < 0) break;
         n++;m++;
        cout<<((TA[m] - TA[n - 1]) + MOD) % MOD<<"\n";
    }
    return 0;
}
