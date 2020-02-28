#include<bits/stdc++.h>

using namespace std;
string cad;
int main ()
{
     int N;
       cin>>N;
       for(int i = 0;i < N;i++){
   cin>>cad;
    reverse(cad.begin(),cad.end());
      if((cad[0]-'0') % 2 == 0)
        cout<<"even"<<endl;
      else 
         cout<<"odd"<<endl;
        }
return 0;
}