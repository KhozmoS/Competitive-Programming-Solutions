#include<bits/stdc++.h>
using namespace std;
  int test,bank,N,ad;
  char acc;
int main ()
{
    cin>>test;
       for(int t = 0; t < test;t++)
       {
         cin>>bank;
          cin>>N;
          for(int i =0;i < N;i++)
          {
              cin>>acc>>ad;
              if(acc == 'C')
                bank += ad;
              else
                 bank -= ad;

          }
           cout<<bank<<endl;
       }


    return 0;
}
