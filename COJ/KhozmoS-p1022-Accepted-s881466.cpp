#include<bits/stdc++.h>
using namespace std;
   const int MAX = 53;
   int A[MAX];
  int N,ta,aux,sol;
  int pegar;
int main ()
{
      ios_base::sync_with_stdio(0);cin.tie(0);
       cin>>N;
        for(int t = 0; t < N; t++){
           cin>>ta;
          for(int i = 0;i < ta;i++){
            cin>>pegar;
            A[i] = pegar;
          }
           for(int i = 0; i < ta - 1; i++)
           for(int j = ta - 1; j > i; j--){
             if(A[j] < A[j - 1]){
               aux = A[j];
               A[j] = A[j - 1];
               A[j - 1] = aux;
               sol++;
             }
           }
            cout<<"Optimal train swapping takes "<<sol<<" swaps."<<endl;
            sol = 0;

      }
    return 0;
}
