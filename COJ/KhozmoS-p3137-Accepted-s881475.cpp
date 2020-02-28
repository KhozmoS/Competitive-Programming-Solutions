#include<bits/stdc++.h>
using namespace std;
   int N;
   int a,b,c;
int main ()
{

      scanf("%d",&N);
        for(int i = 0; i < N; i++){
         scanf("%d%d%d",&a,&b,&c);
              if(b != 0){
            if(a + b == c || a - b == c || a / b == c || a * b == c || a % b == c)
                printf("YES\n");
            else
                printf("NO\n");
              }
              else{
             if(a + b == c || a - b == c || a * b == c )
                printf("YES\n");
             else
               printf("NO\n");
              }


        }


    return 0;
}
