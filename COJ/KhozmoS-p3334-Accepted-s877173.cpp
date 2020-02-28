#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int N,L;
    string S,P;
      cin >> N >> S >> L >> P;
    int j = 0;
    int cont = 0;
      for(int i=0;i<N;i++){
        if(S[i] == P[j]){
            j++;
            if(j == L ){
                j = 0;
                cont++;
            }
        }
       }
         if(cont == 0)
           cout <<"-1" <<endl;
           else
            cout << N - (L * cont)<<endl;
    return 0;
}
