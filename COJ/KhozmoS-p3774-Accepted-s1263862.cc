#include <bits/stdc++.h>

using namespace std;
#define PB push_back
const int MAX = 1e6+1;
typedef long long ll;
int t;
int v[MAX];
vector <int> adl[MAX];

int dp[MAX];
bool mk[MAX];

int dfs(int node , int mx_u)
{
    int mx_d = 0;
    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int nw = adl[node][i];
        if(!mk[nw]){
            mk[nw] = true;
            mx_d = max(dfs(nw , max(mx_u , v[node])) , mx_d);
        }
    }
    dp[node] = max(mx_u , mx_d);
    return max(mx_d , v[node]);
}
int ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int i = 1 ; i <= t ; i++)
    {
        cin>>v[i];
        ans = max(v[i] , ans);
    }
    for(int i = 1 ; i < t ; i++)
    {
        int a, b;cin>>a>>b;

        adl[a].PB(b);
        adl[b].PB(a);
        
    }
    mk[1] = true;
    
    int l = dfs(1 , 0);
    
    for(int i = 1 ; i <= t; i++)
    {
        if(v[i] < dp[i]) continue;
        
        ans = min(ans , v[i]);
    }
    cout<<ans<<"\n";
}
