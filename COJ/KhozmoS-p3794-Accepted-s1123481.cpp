    #include <bits/stdc++.h>

    using namespace std;

    typedef int ll;

    const int MAX = 1e3 + 5;
    const long long mod = 1000000007;

    ll cd[MAX * 5];

    ll dp[MAX * 5][MAX * 5];
    ll dp1[MAX * 5][MAX * 5];
    ll P[MAX * 5][MAX * 5];

    void PASCAL()
    {
      P[0][0] = 1;

      for(int i = 0 ; i < MAX * 5; i++)
        P[i][0] = 1;
      for(int i = 0 ; i < MAX * 5; i++)
        P[i][i] = 1;

      for(int i = 1 ; i < MAX * 5; i++)
        for(int j = 1 ; j < i ; j++)
          P[i][j] = (P[i - 1][j] + P[i - 1][j - 1]) % mod;

    }

    int main()
    {
        PASCAL();
        //cout<<P[3][2];
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        for(int i = 2 ; i < MAX * 5; i++)
          for(int j = 1 ; j < i ; j++)
            if(i % j == 0)
            cd[i]++;


        for(int i = 1 ; i < MAX * 5 ; i++)
         for(int k = 1 ; k < MAX * 5 ; k++){
           dp[i][k] = min(k , cd[i]) + dp[i - 1][k] ; dp[i][k] %= mod;
           }
        for(int i = 0 ; i < MAX * 5 ; i++)
          dp1[0][i] = 1ll;

        for(int i = 1 ; i < MAX * 5; i++)
         for(int k = 1 ; k < MAX * 5; k++)
          {
            dp1[i][k] = dp1[i - 1][k];
            if(k < cd[i]){
             long long ping = ((long long)dp1[i][k] * (long long)P[cd[i]][k]) % mod;
             dp1[i][k] = (int)ping;
             }
          }
        int t;

        cin>>t;
        while(t--)
        {
           int n , k;
           cin>>n>>k;

           cout<<dp[n][k]<<" "<<dp1[n][k]<<"\n";
        }



        return 0;
    }
