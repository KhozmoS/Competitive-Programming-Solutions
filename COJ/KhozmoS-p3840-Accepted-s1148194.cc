#include <bits/stdc++.h>

using namespace std;

#define prof first
#define act second
typedef long long ll;
typedef pair <ll , ll> par;
par dp[500][2];
ll ar[500];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[0][0] = par(100 , 0);
    dp[0][1] = par(100 , 0);


    ll ans = 100;

    int n; cin>>n;
    for(int i = 1 ; i <= n ; i++) cin>>ar[i];

    for(int i = 1 ; i <= n ; i++)
        for(int j = i - 1 ; j >= 0 ; j--)
        {
            if(dp[i][1].prof < (dp[j][0].act * ar[i]) + dp[j][0].prof)
            {
               dp[i][1].prof = dp[j][0].prof + (dp[j][0].act * ar[i]);
               dp[i][1].act = 0;
               ans = max(ans , dp[i][1].prof);
            }

            ll ac = dp[j][1].prof / ar[i];
            ac = min(ac , 100000 - dp[j][1].act);
            if(dp[i][0].act < ac + dp[j][1].act || (dp[i][0].act == ac + dp[j][1].act && dp[i][0].prof < (dp[j][1].prof - (ac * ar[i])))){
               dp[i][0].act = ac + dp[j][1].act;
               dp[i][0].prof = (dp[j][1].prof - (ac * ar[i]));
               ans = max(ans , dp[i][0].prof);
            }
        }
        cout<<ans<<"\n";
}
