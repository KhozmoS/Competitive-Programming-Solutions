#include<bits/stdc++.h>


using namespace std;

long long int dp[500][500];
int N;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int k = 1 ; k <= n ; k++)
    {
      cin>>N; int sol;
      for(int i = 1 ; i <= N ; i++)
      for(int j = 1 ; j <= i ; j++){
      cin>>dp[i][j];
      dp[i][j] += max(dp[i - 1][j - 1] , dp[i - 1][j]);
      }
      for(int i = N + 1 ; i <= (2 * N) - 1 ; i++){
      //cout<<2 * (N - 1)<<"\n";
      for(int j = 1 ; j <= N - (i - N) ; j++){
      cin>>dp[i][j];
      dp[i][j] += max(dp[i - 1][j] , dp[i - 1][j + 1]);
      sol = dp[i][j];
      }}
       cout<<"Case "<<k<<": "<<sol<<"\n";
    }

    return 0;
}
