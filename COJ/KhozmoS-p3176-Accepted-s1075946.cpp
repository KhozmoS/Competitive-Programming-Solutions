#include <bits/stdc++.h>

using namespace std;

const int MAX = 35;

double dp[105][605];
bool mk[105][605];

double F(int n , int k)
{
   if(mk[n][k])
    return dp[n][k];

    if(!n)
     return 0;

   if(k <= 0)
    return 0;

    mk[n][k] = true;
    double &s = dp[n][k];
    s=0;

   for(int i = 1 ; i <= 6 ; i++){
    s += F(n - 1 , k - i);
   }
   return s;
}

int main()
{
   // cout<<"wa";
  //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;

    cin>>t;
    while(t--){

    //memset(dp , -1 , sizeof(dp));
    memset(mk , 0 , sizeof(mk));
    dp[0][0] = 1.0;
    mk[0][0]=true;
    double n , k;
    cin>>n>>k;

    double n1 = n;
    double sol = F(n , k);
    double  den = pow(6 , n);

    printf("%.2lf\n", sol / den);
    }
    return 0;
}
