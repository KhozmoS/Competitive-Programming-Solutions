#include <bits/stdc++.h>
//khozmoS   A
using namespace std;
 int TA[1005];
  bool is_prime(int a)
  {
     if(a % 2 == 0)
       return false;
      for(int i = 3 ; i * i <= a ; i += 2)
        if(a % i == 0)
         return false;

        return true;

  }
  void primos()
  {
    TA[1] = 2;
     int j = 2;
     for(int i = 3 ; i < 1005 ; i++)
     {

       if(is_prime(i)){
         TA[j] = i;
         j++;
         }
     }
  }
  int t;
  int N;
int main()
{
//ios_base::sync_with_stdio(0);cin.tie(0);
   primos();
    cin>>t;
     while(t--)
     {
       int cont = 0;
       cin>>N;
        /*if(N == 1)
         cout<<0<<"\n";*/
        // else{
       int i = 1;
      while(TA[i] <= N && TA[i] != 0){
        if(N % TA[i] == 0)
         cont++;
         i++;
      }
       cout<<cont<<"\n";
       }
    // }
    return 0;
}
