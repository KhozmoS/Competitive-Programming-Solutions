#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAX = 1e3 * 2;
ll P[MAX+5][MAX+5];
const ll mod = 1e9 + 7;

void PASCAL()
{

    for(int i = 0 ; i <= MAX ; i++)
        P[i][0] = P[i][i] = 1;

    for(int i = 1 ; i <= MAX ; i++)
        for(int j = 1 ; j <= i ; j++)
           P[i][j] = (P[i - 1][j - 1] + P[i - 1][j]) % mod;

}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   PASCAL();
   int N = 0, K = 0;
   while(cin>>N>>K)
   {
      ll ans = 1;
      K = N /  K;
      while(N)
      {
          ans = (ans * P[N][K]) % mod;
          N -= K;
      }

      cout<<ans<<"\n";
   }
}


