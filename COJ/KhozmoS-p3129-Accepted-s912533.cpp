#include <bits/stdc++.h>

using namespace std;
int n , p , t , i = 1, sol;
string cad;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while( t-- )
    {
       cin>>n>>cad>>p;
        if(cad == "odd")
          {
              sol = 2;
              while(i < p)
              {
                  sol += 2;
                  i++;
              }
             cout<<sol<<"\n";
             i = 1;
             sol = 0;
          }
         else{
             sol = 1;
            while(i < p)
            {
                sol += 2;
                i++;
            }
             cout<<sol<<"\n";
             i = 1;
             sol = 0;
         }
    }
    return 0;
}
