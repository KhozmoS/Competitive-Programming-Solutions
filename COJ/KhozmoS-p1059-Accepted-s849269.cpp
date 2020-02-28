#include <bits/stdc++.h>

using namespace std;

int main()
{
     int n;

       string bin="";
       int cont=1;
       while(true)
       {   cin>>n;
           if(n==0)
           break;


      while(n!=1)
      {


          if(n%2==0)
           bin="0"+bin;
           else
           {
               bin="1"+bin;
               cont++;
           }

            n/=2;

      }
        bin="1"+bin;
           cout<<"The parity of "<<bin<<" is "<<cont<<" (mod 2)."<<endl;
           bin="";
           cont=1;

       }


    return 0;
}
