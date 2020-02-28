#include <bits/stdc++.h>

using namespace std;


int freq[5];

string solu = "ACGT";

int main()
{
   string cad;
   cin>>cad;

     for(int i = 0 ; i < cad.size() ; i++)
     {
        if(cad[i] == 'A')
         freq[0]++;
        else if(cad[i] == 'C')
         freq[1]++;
        else if(cad[i] == 'G')
         freq[2]++;
        else
         freq[3]++;
     }
     int pos; int men = 10000000000;

      for(int i = 0 ; i < 4 ; i++)
      {
        if(men > freq[i])
        {
          men = freq[i];
          pos = i;
        }
      }
       if(freq[pos] == 0) 
       cout<<solu[pos]<<"\n";
       else
        cout<<"A\n";
        // else

    return 0;
}
