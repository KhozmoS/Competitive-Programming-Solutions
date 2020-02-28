#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6+1;
 int N;
 int a , b , c;

    struct ABI {
      int T [SIZE];
      ABI(){
      fill(T , T+SIZE ,0);
      }

    void update (int pos, int valor){
        for(;pos < SIZE ; pos += (pos & -pos))
            T[pos]+=valor;
    }

 int suma (int pos){
    int R=0;
       for ( ; pos > 0 ;pos -= (pos & -pos) )
              R+=T[pos];

                return R;
    }

}abi;

int main()
{
 ios_base ::sync_with_stdio(0);
 cin.tie(NULL) ;

   cin >> N;
    while(N -- ){
         cin >> a;
         if(a == 1){
                cin >> b;
                abi.update(b,1);
            }

        else{
                cin >> b >> c;
           cout <<  abi.suma(c) - abi.suma(b-1) << '\n';
           }

    }


}
