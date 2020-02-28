#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
#define ll long long
const ll inf = 1e9 + 100;

ll dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;

    cin>>t; while(t--){
    for(int i = 1 ; i <= 100 ; i++)
    for(int j = 1 ; j <= 100 ; j++) dp[i][j] = inf;

    int n , m; cin>>n>>m;
    while(m--)
    {

        ll a , b , c; cin>>a>>b>>c;

        dp[a][b] = min(c , dp[a][b]);
        dp[b][a] = min(c , dp[b][a]);
    }

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
               dp[i][j] = min(dp[i][k] + dp[k][j] , dp[i][j]);

    int q;cin>>q;
    while(q--){int a , b; cin>>a>>b; if(dp[a][b] == inf && a != b) cout<<"-1\n";else if(a == b) cout<<"0\n"; else cout<<dp[a][b]<<"\n";}
    if(t) cout<<"\n";
    }
}
