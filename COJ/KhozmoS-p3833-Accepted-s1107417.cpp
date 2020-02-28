#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int, int> par;
typedef vector<int> vec;


map <string , bool> m;
char dir[10][2];
char ar[10][2];
int fac[10];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   double n;
   cin>>t;
   while(t--)
   {
       double ans = 0.0;
       cin>>n;
       for(int i = 1 ; i <= n ; i++)
        ans += (n / (.0 + i));
        cout<<setprecision(2)<<fixed<<ans<<"\n";
   }
    return 0;
}
