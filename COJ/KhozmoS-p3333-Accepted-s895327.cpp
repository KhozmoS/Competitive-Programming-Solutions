#include <bits/stdc++.h>

using namespace std;
  const int MAX = 100005;
  int A[MAX];
   int TA[MAX];
  int N,S,Q,I,J,sol,sum;
int main()
{
    scanf("%d",&N);
     for(int i = 1;i <= N ; i++)
     {
         scanf("%d",&S);
         A[i] = S;
     }
      for(int i = 1 ; i <= N ; i++)
      {
          sum += A[i];
          TA[i] = sum;
      }
      scanf("%d",&Q);
       for(int i = 0;i < Q ;i++)
       {
          scanf("%d",&I);
          scanf("%d",&J);
           printf("%d\n" , (TA[J] - TA[I - 1]));
       }

    return 0;
}
