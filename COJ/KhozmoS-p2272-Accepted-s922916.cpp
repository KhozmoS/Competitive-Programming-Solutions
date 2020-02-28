#include <bits/stdc++.h>
#define MAXN 1e9 * 4
using namespace std;

 typedef long long LL;
 bool is_prime(LL n)
 {
     if(n <= 1)
     return false;
     if(n == 2)return true;
     if(n % 2 == 0)
     return false;
     for(LL i = 3 ; i * i <= n; i += 2)
     if(n % i == 0)
     return false;

     return true;
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;

  LL N;
  cin>>t;
   while(t--)
   {
       cin>>N;
       while(!is_prime(N++));

       cout<<--N<<"\n";
   }
    return 0;
}
