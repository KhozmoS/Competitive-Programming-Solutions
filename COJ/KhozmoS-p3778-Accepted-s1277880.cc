#include <iostream>
#include <bits/stdc++.h>
using namespace std;


typedef long long ll ;
const ll MOD = 1e9+7;
const int SIZE = 1e6+2 ;

ll T[SIZE];
void solve(){

       T[0]= 1;
        T[1] = 1;
         T[2]= 1 ;
          for(ll i = 3;i < SIZE ; i++){
             T[i] =  (T[i-1]*(i-1) %MOD + ((i-2)*T[i-2])%MOD) %MOD ;
          }


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

     int Q;
     cin >>Q;
    solve();
  while(Q -- ){

     int a;cin >>a ;

     cout << T[a]  << '\n';

  }

}
