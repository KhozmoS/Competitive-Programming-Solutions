#include<bits/stdc++.h>
using namespace std;
int acm,sol;
  int factorial(int k)
  {
      int fact = 1;
      for(int i = 1;i <= k ;i++ )
      {
          fact *= i;
      }
      return fact;
  }
int main ()
{

   int her;
   int k;
       while(true){
        scanf("%d", &acm);
          if(acm == 0)
           break;
           k = 1;
       while(acm != 0){
          her = acm % 10;
            if(k != 1)
          sol += ( her * factorial ( k ) );
            else
           sol += her;
           acm /= 10;
          k++;
                    }
         printf("%d\n",sol);
           sol = 0;
      }
    return 0;

}
