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
   while(t--)
   {
       string cad;
       cin>>cad;
       int x = cad.size();
       if(!(x & 1)) cout<<"Non-inhabitant\n";
       else{
          int ans = 0;
          for(int i = 1 ; i <= x ; i += 2)
              ans += i;

          cout<<"The inhabitant "<<cad<<" can have "<<ans<<" children\n";
       }
   }
   return 0;
}
