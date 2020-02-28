#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int j = 0;
 string cad;
 string sol = "";
 string resp = "";
   cin>>cad;
    for(int i = 0;i < cad.size();i++){
      if(cad[i] != '+')
        sol += cad[i];
    }
       sort(sol.begin(),sol.end());
       for(int i = 0;i < cad.size();i++){
            if(i % 2 == 0){
              resp += sol[j];
              j++;
              }
             else
              resp += '+';
                                  }
             cout<<resp<<endl;
 return 0;
}
