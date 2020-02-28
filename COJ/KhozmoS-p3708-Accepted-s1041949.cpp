#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
int n;
const int MAXN = 505;


ll dp[MAXN];


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);


    for(int i = 1 ; i <= 5 ; i++)
        dp[i] = 1<<(i - 1);

    for(int i = 6 ; i <= 500 ; i++)
    {
        ll cont = 0;
      for(int j = 0 ; j <= i - 2 ; j++)
      {
        ll a = j;
        ll b = i - 2 - j;
        cont += (a * b) + 1;
      }

      dp[i] = dp[i - 1] + cont;
    }

    int t , x;

    cin>>t;
    while(t--)
    {
        cin>>x;

        cout<<dp[x]<<"\n";
    }

    return 0;
}
