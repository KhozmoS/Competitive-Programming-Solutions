#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define f first
#define s second
#define PB push_back

typedef pair <ll , ll> par;
typedef pair <par , int> trio;
const int MAX = 205;

vector <par> v[MAX];

ll edge[MAX][MAX] , dp[MAX][MAX];
par DP[MAX][MAX];
bool mk[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , m;cin>>n>>m;
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++){
            if(i!=j){
                dp[i][j] = INT_MAX;
               // mk[i][j] = true;
            }
        }
    while(m--)
    {
        int i, j ,c;cin>>i>>j>>c;

        if(c < dp[i][j]){
            dp[i][j] = c;
            dp[j][i] = c;

            edge[j][i] = c;
            edge[i][j] = c;
            mk[i][j] = true;
            mk[j][i] = true;
        }
    }
    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                if(dp[i][j] > dp[i][k]+dp[k][j])
                {
                    dp[i][j] = dp[i][k]+dp[k][j];
                    if(edge[i][j] > dp[i][j]){
                        mk[i][j] = false;
                        //cout<<i<<" "<<j<<"\n";
                    }
                }
   for(int i = 0 ; i < MAX ; i++)
       for(int j = 0 ; j < MAX ; j++)
           if(i!=j)  DP[i][j] = par(INT_MAX , INT_MAX);

   for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= n ; j++)
           if(edge[i][j])
                DP[i][j] = par(mk[i][j] , edge[i][j]);

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
            {
                par nw = par(DP[i][k].f+DP[k][j].f , DP[i][k].s+DP[k][j].s);
                DP[i][j] = min(DP[i][j] , nw);
            }
    int q;
    cin>>q;
    while(q--)
    {
        int a, b;cin>>a>>b;
        cout<<DP[a][b].s<<"\n";
    }
}
/*
4 5
1 2 30
1 3 20
1 4 40
2 3 100
3 4 100
4
1 3
1 4
2 4
1 1
*/
