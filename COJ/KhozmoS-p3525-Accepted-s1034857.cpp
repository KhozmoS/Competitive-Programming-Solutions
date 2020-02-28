#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int MAXN = 1005;


ll t , n;
ll a[MAXN] , b[MAXN];
ll P[MAXN][MAXN];

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1ll)
            ans = (ans * a) % mod;
        b >>= 1ll;
        a = (a * a) % mod;
    }
    return ans;
}
ll ta[MAXN][MAXN];

void PASCAL()
{
    P[0][0] = 1;
    for(int i = 1 ; i < MAXN ; i++)
      for(int j = 1 ; j <= i ; j++)
       P[i][j] = ((P[i - 1][j] % mod) + (P[i - 1][j - 1]) % mod) % mod;
}
void tabla()
{
  for(int i = 1 ; i < MAXN ; i++)
   for(int j = 1 ; j < i ; j++)
   {
     ta[i][j] = (ta[i][j - 1] + P[i + 1][j + 1]) % mod;
   }
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   PASCAL();
   P[1][1] = 0;
   tabla();
   //cout<<P[6][4];
   cin>>t;
   while(t--)
   {
      cin>>n;
      ll sol = 1;
      for(int i = 0 ; i < n ; i++)
      {
       cin>>a[i];
      }
      for(int i = 0 ; i < n ; i++)
      {
       cin>>b[i];
      }
      for(int i = 0 ; i < n ; i++)
      {
       if(a[i] > b[i])
       {
           sol = (sol * ((exp(2 , b[i]) - 1 + mod) % mod)) % mod;
       }
       else
       {
           //cout<<ta[b[i]][a[i] - 1]<<" "<<a[i]<<" "<<b[i]<<"\n";
           ll sum = ta[b[i]][a[i] - 1];
           sol = (sol * sum) % mod;
       }

      }
      cout<<sol<<"\n";
   }



    return 0;
}
