#include <bits/stdc++.h>

using namespace std;
const int MAX = (1e5 + 3) * 2;
bool dp[MAX];
int ar[MAX];
int t;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>t;

   for(int i = 0 ; i < t ; i++){
    cin>>ar[i];
   }
   dp[t] = true;
   int n = t;
   n--;
   do
   {

     if(dp[ar[n] + n + 1])
        dp[n] = true;

   }while(n--);
   //if(dp[0]) cout<<"0/\n";
   for(int i = 0 ; i <= t; i++)
      if(dp[i])
        cout<<i<<"\n";
    return 0;
}
