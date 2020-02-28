#include <bits/stdc++.h>

using namespace std;


int dp[45005] , n , ar[505], s;


int main()
{

    cin>>s>>n;
    dp[0] = true;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) cin>>ar[i];

    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        x = ar[i];
        for(int j = s ; j >= 0 ; j--)
            if(dp[j] && j+x<=s){
                dp[j+x] = true;
                ans = max(ans , j+x);
            }
    }
    cout<<ans<<"\n";
}
