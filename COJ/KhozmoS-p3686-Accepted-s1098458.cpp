#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e6 + 5;

int t , n , k , RMQ[MAX][25];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;

   while(t--)
   {
      cin>>n>>k;
      for(int i = 1 ; i <= n ; i++) cin>>RMQ[i][0];

      for(int j = 1 ; (1 << j) <= n ; j++)
         for(int i = 1 ; i + (1 << j) - 1 <= n ; i++)
           RMQ[i][j] = max(RMQ[i][j - 1] , RMQ[i + (1 << (j - 1))][j - 1]);

      int l = log2(k);

      for(int i = 1 ; i + k - 1 <= n ; i++)
         cout<<max(RMQ[i][l] , RMQ[(i + k - 1) - (1 << l) + 1][l])<<(i + k > n ? "\n" : " ");
   }

    return 0;
}
