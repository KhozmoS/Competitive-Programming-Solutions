#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 5;
const ll mod = 1e9 + 7;

ll H[MAX] , R[MAX] , bas = 611;



ll sub(ll s , ll e)
{
    return ((long long)H[e] - (long long)(H[s-1] * R[e-s+1])%mod + mod) % mod;
}
int dp[MAX];
//ll calc_hash(int s, int e){return (( H[e] - (H[s] * P[e-s]) % mod + mod) % mod);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   R[0] = 1ll;
   string a;
   int t;cin>>t;
   while(t--){
       cin>>a;
       int sza = a.size();
       a = " " + a;
       H[0] = 0;
       R[0] = 1;
       for(int i = 1 ; i <= sza ; i++)
       {
           H[i] = (H[i-1] * bas + (a[i] - 'a')) % mod;
           R[i] = (R[i-1] * bas) % mod;
       }
       for(int sz = 1 ; sz <= sza ; sz++){

          if(sza % sz == 0){
                bool flag = true;
                for(int i = 1 ; i <= sza ; i += sz)
                {
                    if(sub(i , i + sz-1) != H[sz]){
                        flag = false;
                        break;
                    }
                }
                if(flag){cout<<sz<<"\n";break;}
          }
       }
   }


}
