#include <bits/stdc++.h>
#define MAXN 500000
using namespace std;
int t , n , sol;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>t;
   while(t--)
   {
       cin>>n;
     sol += 1;
     sol += n;
      if(n == 1){cout<<1<<"\n";sol = 0;continue;}
     else if(n % 2 != 0){
      for(int i = 3 ; i * i <= n ; i++)
      {
         if(n % i == 0){
         sol += i;
         int c = n / i;
         if(c * c != n)
          sol += n / i;
         }
      }
     }
     else
     {
      for(int i = 2 ; i <= n / 2 ; i++)
      {
          if(n % i == 0)
           sol += i;
      }
     }
      cout<<sol<<"\n";
      sol = 0;
   }
  return 0;
}

