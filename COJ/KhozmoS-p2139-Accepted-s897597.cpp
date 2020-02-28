#include<bits/stdc++.h>
using namespace std;

int cont , tac;
string cad , comp;
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>cad>>comp)
    {
        int i = 0;
         tac = cad.size();
         for(int j = 0 ; j < comp.size() ; j++)
         {
             if(cad[i] == comp[j])
             {
                 cont++;
                 i++;
             }
         }
          if(tac == cont)
            cout<<"Yes"<<"\n";
          else
            cout<<"No"<<"\n";
          cont = 0;
          i = 0;

    }
    return 0;
}
