#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int n , fr , dp[MAX] , tot , best , go[MAX] , f[MAX];
map <int , int> arist [MAX];

int F(int node)
{
    if(node == 1) return 0;
    if(dp[node] != -1) return dp[node];

    tot += arist[node][go[node]];

    dp[node] = F(go[node]) + arist[node][go[node]];

    best = max(best , dp[node]);
    return dp[node];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    memset(dp , -1 , sizeof(dp));
    cin>>n>>fr;
    for(int i = 1; i < n ; i++)
    {
        int a , b , c;
        cin>>a>>b>>c;
        arist[b][a] = c;
        go[b] = a;
    }
    for(int i = 1 ; i <= fr ;i++) cin>>f[i];

    for(int i = 1 ; i <= fr ; i++){
        int x = f[i];
        if(dp[x] == -1) F(x);
    }
        //cout<<tot<<" "<<best<<"\n";
    cout<<tot-best<<"\n";
}
