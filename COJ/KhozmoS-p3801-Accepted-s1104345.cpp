#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000;
int t;
ll n , r1 , r2;
ll ar[1005];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;

   for(int cas = 1 ; cas <= t ; cas++)
   {
       cin>>n>>ar[1]>>ar[2];

       for(int i = 3 ; i <= n ; i++)
         ar[i] = (ar[i - 1] * ar[i - 2]) % mod;

       cout<<"At week "<<(n * 3) - 2<<" we obtain "<<ar[n]<<" new rabbits.\n";
   }
   return 0;
}
