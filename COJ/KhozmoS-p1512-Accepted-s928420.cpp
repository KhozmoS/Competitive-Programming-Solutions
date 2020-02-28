#include <bits/stdc++.h>

using namespace std;
 typedef long long LL;
 LL n; int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
   while(t--)
   {
       cin>>n;
       cout<<(n * (n - 1)) + 2<<"\n";
   }
    return 0;
}
