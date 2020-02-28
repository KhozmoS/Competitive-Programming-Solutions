#include<bits/stdc++.h>

using namespace std;

 vector<int>fac[8];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1 ; i <= 7 ; i++)
    {
        fac[i].push_back(i);
        for(int j = 1 ; j <= 3 ; j++)
        {
            int x;
            cin>>x;
            fac[i].push_back(x);
        }
    }
    /*for(int i = 1 ; i <= 7 ; i++)
     {
         cout<<"Facultad ";
         for(int j = 0 ; j < 4 ; j++)
          cout<<fac[i][j]<<" ";
          cout<<"\n";
     }*/
     vector<int>aux;
     for(int i = 1 ; i < 7 ; i++)
     {
         int pos = i;
         for(int j = i + 1 ; j <= 7 ; j++)
         {
             if(fac[pos][1] == fac[j][1])
             {
               if(fac[pos][2] == fac[j][2])
               {
                   if(fac[pos][3] == fac[j][3])
                   {
                       if(fac[pos][0] < fac[j][0])
                       {
                           pos = j;
                       }
                   }
                   else if(fac[pos][3] < fac[j][3])
                   pos = j;
               }
                else if(fac[pos][2] < fac[j][2])
                pos = j;
             }
             else if(fac[pos][1] < fac[j][1])
             pos = j;
         }
           //swap
           if(pos != i)
           {
               aux = fac[pos];
               fac[pos] = fac[i];
               fac[i] = aux;
           }

     }
     for(int i = 1 ; i <= 7 ; i++)
     {
         cout<<"Facultad ";
         for(int j = 0 ; j < 4 ; j++)
          cout<<fac[i][j]<<" ";
          cout<<"\n";
     }
    return 0;
}
