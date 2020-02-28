#include <bits/stdc++.h>

using namespace std;

int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);

   int n; cin>>n;
   double A , S , L , x;

   while(n--){
         cin>>A; cin>>S;
         S /= 2;
         S *= S;
         x = S - A;
         cout<<setprecision(2)<<fixed<<sqrt(x)<<'\n';
   }
   return 0;
}
