#include <bits/stdc++.h>

using namespace std;


int dp[45005] , n , ar[505], s;


int main()
{

    cin>>n>>s;
    dp[0] = 1;
    int ans = 0;


    for(int i = 1 ; i <= n ; i++)
    {
        int x , v;
        cin>>x>>v;
        for(int j = s ; j >= 0 ; j--)
            if(dp[j] && j+x<=s && dp[j+x] < dp[j] + v){
                dp[j+x] = dp[j] + v;
                ans = max(ans , dp[j+x]);
            }
    }
    cout<<ans-1<<"\n";
}
