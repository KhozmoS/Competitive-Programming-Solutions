#include <bits/stdc++.h>

using namespace std;
 string cad;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     int cont = 0;
     int t;
     cin>>t;
     while(t --)
     {
         int cont = 0;
         bool no = false;
         cin>>cad;
         int ta = cad.size();
         bool flag = false;
         for(int i = 0 ; i < ta - 2 ; i++)
         {
             if(cad[i] == 'C')
             {
                 for(int j = i + 1 ; j < ta - 1 ; j++)
                 {
                     if(cad[j] == 'A')
                     {
                         for(int k = j + 1 ; k < ta ; k++)
                         {
                             if(cad[k] == 'T')
                             {
                                cont++;
                             }
                         }

                     }

                 }
             }


         }
         cout<<cont<<"\n";
     }

    return 0;
}
