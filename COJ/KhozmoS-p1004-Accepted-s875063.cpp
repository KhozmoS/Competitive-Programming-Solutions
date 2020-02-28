#include <bits/stdc++.h>

using namespace std;
   int f,c;
int main()
{    int N;
      scanf("%d",&N);
        for(int i=0;i<N;i++){
    scanf("%d %d",&f,&c);
      if(f <= c && f % 2==0){
        printf("%s","L");
        printf("\n");}
      else if(f <= c && f % 2 ==1){
         printf("%s","R");
        printf("\n");}
      else if(f > c && c % 2 == 0){
         printf("%s","U");
        printf("\n");}
      else{
         printf("%s","D");
        printf("\n");}
        }
    return 0;
}
