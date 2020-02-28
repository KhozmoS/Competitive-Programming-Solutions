#include<bits/stdc++.h>


using namespace std;

const int MAX = 205;
const int mod = 1000000007;

int M[MAX][MAX];
int dp[MAX][MAX];
bool mk[MAX][MAX];
int f , c , k;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>f>>c>>k;

    for(int i = 1 ; i <= f ; i++)
       for(int j = 1 ; j <= c ; j++)
         cin>>M[i][j];
    dp[1][1] = 1;
    for(int i = 1 ; i <= f ; i++)
       for(int j = 1 ; j <= c ; j++)
         for(int l = i + 1 ; l <= f ; l++)
          for(int k = j + 1 ; k <= c ; k++)
            if(M[i][j] != M[l][k]){
              dp[l][k] += dp[i][j];
              dp[l][k] %= mod;    
              }

    cout<<dp[f][c]<<"\n";

   return 0;
}
/*
7
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 0 1 0 1 1
1 1 1 0 1 1 1
1 1 0 1 0 1 1
1 1 1 1 1 1 1
*/
