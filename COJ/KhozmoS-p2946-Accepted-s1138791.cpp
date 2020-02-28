#include<bits/stdc++.h>

using namespace std;
int n;
 int a;
int main()
{
     scanf("%d",&n);
      for(int i = 0; i < n ; i++)
      {
          scanf("%d",&a);
           if(a % 2 == 0){
            while(a % 2 == 0)
           {
              a /= 2;
           }
             printf("%d\n",a);
           }
           else{      
            printf("%d\n",a*2);
           }
      }
   return 0;
}
