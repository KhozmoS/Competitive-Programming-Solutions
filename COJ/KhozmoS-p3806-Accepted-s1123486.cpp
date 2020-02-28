#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;


bool mk[MAX];
const int maxn = 1e4 + 5;
int dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[1] = 1 , dp[2] = 2;
    mk[1] = true; mk[2] = true;

    for(int i = 3 ; i < maxn ; i++)
     for(int j = dp[i - 1] + 1 ; ; j++)
     {
      int cont = 0;
      int k = i - 1;
      while(j - dp[k] < dp[k])
      {
        if(mk[j - dp[k]])
            cont++;
        if(cont > 2)
            break;
        k--;
      }
      if(cont == 1)
      {
          dp[i] = j;
          mk[j] = true;
          break;
      }
     }
    int t , n;
    cin>>t;
    while(t--)
       cin>>n,cout<<dp[n]<<"\n";
}
