#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int dp[MAX][10];
bool mk[MAX];


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
     int n , q;
     while(cin>>n)
     {
        memset(dp , 0 , sizeof(dp));

       for(int i = 1 ; i <= n ; i++)
       {
         int x;
         cin>>x;
         dp[i][x]++;
       }
       for(int i = 0 ; i <= 9 ; i++)
        for(int j = 1 ; j <= n ; j++)
         dp[j][i] += dp[j - 1][i];

       cin>>q;
       while(q--)
       {
        int ans = 0;
        int a , b;
        cin>>a>>b;
        for(int i = 0 ; i <= 9 ; i++)
        {
          ans += ((dp[b][i] - dp[a - 1][i]) != 0);
        }
        cout<<ans<<"\n";
       }

     }


    return 0;
}
