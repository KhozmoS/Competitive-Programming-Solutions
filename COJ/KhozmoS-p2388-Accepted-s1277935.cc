#include <bits/stdc++.h>

using namespace std;


int dp[10005],n,c;


int F(int x)
{
    if(!x) return 0;
    if(x<=c)
        return 1;
    if(dp[x]!=-1) return dp[x];

    return F(x/2)+F(x/2+x%2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>c;
        cout<<F(n)<<"\n";
    }

}
