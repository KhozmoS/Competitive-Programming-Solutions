#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef vector <int> VI;
typedef long long ll;

VI dp[1005];
int ar[1005];
VI ad[1005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;

    for(int i = 1 ;i <= n ; i++)
    {
        cin>>ar[i];
        for(int d = 1 ; d <= ar[i] ; d++)
        {
            if(ar[i] % d == 0)
            {
                for(int sz = i ; sz > 1 ; sz--)
                {
                    bool flag = false;
                    for(int k = 0 ; k < dp[sz].size() ; k++)
                        if(dp[sz][k] == d)
                          flag = true;

                    if(flag)continue;

                    for(int j = 0 ; j < dp[sz-1].size() ; j++)
                    {
                        if(__gcd(dp[sz-1][j] , ar[i]) == d)
                        {
                           dp[sz].PB(d);
                           break;
                        }
                    }
                }
            }
        }
        dp[1].PB(ar[i]);
    }
    int q;cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        int ans = 0;
        int cur = 1e9;
        for(int i = 1; i <= n ; i++)
          for(int j = 0 ; j < dp[i].size() ; j++)
           if(x <= dp[i][j] && cur >= dp[i][j]){
              ans = i;
              cur = dp[i][j];
           }
        cout<<ans<<"\n";
    }
}
