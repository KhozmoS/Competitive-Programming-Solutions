#include <bits/stdc++.h>

using namespace std;

string num;
int dp[10];
int count(int x)
{
    int ans = 0;

    while(x != 0)
    {
        x /= 10;
        ans++;
    }

    return ans;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

   while(cin>>num)
   {
       if(num == "END") return 0;
       dp[1] = num.size();
       if(num == "1")
       {
           cout<<num<<"\n";
           continue;
       }
       for(int i = 2 ; 1 ; i++)
       {
           dp[i] = count(dp[i - 1]);
           if(dp[i] == dp[i - 1])
           {
               cout<<i<<"\n";
               break;
           }
       }
   }

    return 0;
}
