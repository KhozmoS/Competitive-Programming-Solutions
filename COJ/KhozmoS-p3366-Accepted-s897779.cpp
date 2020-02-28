#include <bits/stdc++.h>
using namespace std;
int A[103];
int mact , men = 10001 , may ,posm , mmay;
int main()
{
    int N;
    cin>>N;
     for(int i = 0 ; i < N ; i++)
     {
       cin>>A[i];
       if(may <= A[i]) {
        posm = i;
        may = A[i];
       }
     }
      bool flag = 0;
     do{
            if(posm == N - 1)
             flag = true;
      for(int i = mmay ; i < posm ; i++)
      {
          if(A[i] < men)
          {
              men = A[i];
          }
      }
      mmay = posm;
       if(may - men > mact)
       mact = may - men;
       may = 0;men = 10001;
       for(int i = posm + 1 ; i < N ; i++)
       {
           if(may < A[i]){
            may = A[i];
            posm = i;
           }
       }
       } while(!flag);
      cout<<mact<<"\n";
    return 0;
}
