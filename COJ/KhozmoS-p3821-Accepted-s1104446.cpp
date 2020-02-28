#include <bits/stdc++.h>

using namespace std;

int ar[15];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   int may = 0;
   cin>>t;
   for(int cas = 1 ; cas <= t ; cas++)
   {
       int ans = 0;
       for(int i = 0 ; i < 10 ; i++) cin>>ar[i] , ans += ar[i];

       sort(ar , ar + 10);

       ans -= (ar[0] + ar[9]);
       may = max(may , ans);
       cout<<cas<<" "<<ans<<"\n";
   }
   cout<<may<<"\n";
    return 0;
}
