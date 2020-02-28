#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[305][305];
int n , m , q;
const ll inf = 1e15;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    for(int i = 1 ; i <=  n ; i++)
        for(int j = 1; j <= n ; j ++)
            dp[i][j] = inf;
    while(m--)
    {
        int a , b;
        ll h;
        cin>>a>>b>>h;
        dp[a][b] = h;
    }
    for(int k = 1 ; k <= n ; k++)
        for(int i = 1; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                dp[i][j] = min(dp[i][j] , max(dp[i][k] , dp[k][j]));
    while(q--)
    {
        int a , b;
        cin>>a>>b;
        if(dp[a][b] == inf)
            cout<<"-1\n";
        else
            cout<<dp[a][b]<<"\n";
    }
}
