#include <bits/stdc++.h>

using namespace std;

#define AreaS(R) 4 * 3.14159 * R * R * R / 3
#define AreaC(R , H) 3.14159 * R * R * H / 3
#define AreaL(R , H) 3.14159 * R * R * H

double ans = 0;
int t;
char c;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>t;
   while(t--)
   {
      cin>>c;
      if(c == 'S')
      {
        double a;
        cin>>a;
        ans = max(ans , AreaS(a));
      }
      else if(c == 'C')
      {
        double a , b;
        cin>>a>>b;
        ans = max(ans , AreaC(a , b));
      }
      else
      {
        double a , b;
        cin>>a>>b;
        ans = max(ans , AreaL(a , b));
      }
   }

   cout<<setprecision(3)<<fixed<<ans<<"\n";
   return 0;
}
