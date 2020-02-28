#include<bits/stdc++.h>


using namespace std;

const int MAX = 1005;
const int mod = 1000000007;

int dp[MAX][MAX];

void update (int l , int pos , int val)
{
   for(int i = pos ; i < MAX ; i += (i & -i)){
     dp[l][i] += val;
     dp[l][i] %= mod;
   }
}

int query(int l , int pos)
{
  int sum = 0;
  for(int i = pos ; i > 0 ; i -= (i & -i))
  {
      sum += dp[l][i];
      sum %= mod;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n , ta , k , t;
    cin>>t;
    while(t--){
     memset(dp , 0 , sizeof(dp));       
    cin>>n>>ta>>k;

    for(int i = 1 ; i <= n ; i++)
     update(1 , i , 1);

    for(int i = 2 ; i <= ta ; i++)
      for(int j = 1 ; j <= n ; j++)
       update(i , j , (query(i - 1 , min(n , j + k)) - query(i - 1 , max(0 , j - k - 1)) + mod) % mod);

     cout<<query(ta , n)<<"\n";
    }
   return 0;
}
