#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;


int dp[MAX];

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    int n , c;
    while(t--)
    {
    bool mk[MAX];

    cin>>n>>c;
    for(int i = 0 ; i < MAX ; i++){
        dp[i] = 0;
        mk[i] = 0;
    }
    int p[n + 5]; int g[n + 5];

    for(int i = 0 ; i < n ; i++)
        cin>>p[i]>>g[i];

     mk[0] = true; int sol = -1;

     for(int i = 0 ; i < n ; i++)
        for(int j = c - p[i] ; j >= 0 ; j--)
         {
          if(mk[j])
          {
            dp[j + p[i]] = max(dp[j + p[i]] , dp[j] + g[i]);
            sol = max(sol , dp[j + p[i]]);
            mk[j + p[i]] = true;
          }
         }
      cout<<sol<<"\n";
    }
    return 0;
}
