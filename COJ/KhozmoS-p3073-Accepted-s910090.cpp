#include<bits/stdc++.h>

using namespace std;
  int t ;
  string cad;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>> t;
     while(t--)
     {
       cin>>cad;
        int tcad = cad.size();
        if( tcad <= 10)
         cout<<cad<<"\n";
        else
         cout<<cad[0]<<tcad - 2<<cad[tcad - 1]<<"\n";

     }

    return 0;
}
