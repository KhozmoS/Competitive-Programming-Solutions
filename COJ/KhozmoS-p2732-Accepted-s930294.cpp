#include <bits/stdc++.h>

using namespace std;
string cad;
int t;
int main()
{
  cin>>t;
   while(t -- )
   {
      cin>>cad;
      for(int i = 0 ; i < cad.size() ; i++)
      {
        if(cad[i] - 'a' >= 0)
         {

           cad[i] =  (char)(cad[i] - 'a' + 'A');

         }
        else
        cad[i] =  (char)(cad[i] - 'A' + 'a');
      }
      cout<<cad<<"\n";
   }
    return 0;
}
