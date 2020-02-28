#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    while(true)
    {

     cin>>a;
   
     cin>>b;
     cin>>c;
   if(c==0)
     break;
        if ((a*a)+(b*b)==c*c)
            cout<<"right"<<endl;
        else if(a*a==(b*b)+(c*c))
            cout<<"right"<<endl;
        else if((a*a)+(c*c)==b*b)
            cout<<"right"<<endl;

        else
            cout<<"wrong"<<endl;

           }
               return 0;
     }