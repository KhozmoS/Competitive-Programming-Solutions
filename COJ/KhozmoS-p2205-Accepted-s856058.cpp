#include <bits/stdc++.h>

using namespace std;
int a,b;
int main()
{
     int N;
     cin>>N;
     string A="";
     int cont=0;
     for(int i=0;i<N;++i)
     {
       cin>>a>>b;
       while(a<=b)
       {
           for(int e=a;e!=0;e/=2)
            {
              if(e%2==1)
                {
                A=A+'1';
                cont++;
                }

            }
            a++;
       }
       cout<<cont<<endl;
        cont=0;
     }
         return 0;
}
