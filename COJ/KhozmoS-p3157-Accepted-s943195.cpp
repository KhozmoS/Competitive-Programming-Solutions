#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
typedef long long LL;
int dice[] = {1 , 2 , 3 , 4 , 5 , 6};
bool mk[MAXN];
int sum[MAXN];

int N , M;
LL dp[MAXN];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    string cad;
    cin>>cad;
    for(int i = 0 ; i < n ; i++)
    {
        if(cad[i] == 'C') dp[0]++;

        else if(cad[i] == 'O') dp[1] += dp[0];

        else dp[2] += dp[1];
    }
    cout<<dp[2]<<"\n";
    return 0;
}
//1 6 2 3 5
// 1 + 5 2 + 4 3 + 3 1 + 5 2 + 4
