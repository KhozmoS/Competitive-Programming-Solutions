#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 5;
const ll mod = 1e9 + 7;
ll Ha[MAX] , bas = 611;
ll Hb[MAX] , R[MAX];



ll sub(ll s , ll e)
{
    return ((long long)Ha[e] - (long long)(Ha[s-1] * R[e-s+1])%mod + mod) % mod;
}
int dp[MAX];
//ll calc_hash(int s, int e){return (( H[e] - (H[s] * P[e-s]) % mod + mod) % mod);}
int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);
   R[0] = 1ll;
   string a , b;
   cin>>a>>b;
   int szb = b.size();
   int sza = a.size();
   //Hash
   for(int i = 1 ; i <= sza ; i++)
   {
       Ha[i] = (Ha[i-1] * bas + (a[i-1] - 'a')) % mod;
       R[i] = (bas * R[i-1]) % mod;
   }
   for(int i = 1 ; i <= szb ; i++)
   {
       Hb[i] = (Hb[i-1] * bas + (b[i-1] - 'a')) % mod;
   }
   //cout<<Hb[szb] <<" "<< sub(1 , szb)<<"\n";
   int ans = 0;
   if(szb > sza){cout<<"0\n";return 0;}
   
   for(int i = 0 ; i + szb <= sza ; i++)
   {
       if(sub(i+1 , i+szb) == Hb[szb]){
           ans++;
           int aux = i;
           for(int j = aux ; j < aux + szb && j + szb <= sza; j++)
           {
               if(Hb[szb] == sub(j+1 , j+szb))
                   i = j + szb - 1;
           }
       }
   }
   cout<<ans<<"\n";
}
