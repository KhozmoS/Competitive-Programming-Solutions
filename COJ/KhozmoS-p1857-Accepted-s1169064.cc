#include <bits/stdc++.h>


using namespace std;

#define db double
db a , b , c;

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);
     cout<<setprecision(3)<<fixed;
     while(cin>>a>>b>>c)
     {
          db sp = (a+b+c)/2.0;
          if(a<=0 || b <= 0 || c <= 0)
          {
              cout<<"The radius of the round table is: ";
              cout<<0.000<<"\n";
              continue;
          }
          cout<<"The radius of the round table is: ";
          cout<<sqrt(sp*(sp - a) * (sp - b) * (sp - c)) / sp<<"\n";
     }

}
