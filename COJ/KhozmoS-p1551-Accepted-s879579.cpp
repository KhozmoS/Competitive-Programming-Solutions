#include<bits/stdc++.h>
using namespace std;

int main ()
{
  int cont = 1;
  int a,b,c;
    while(cin>>a>>b>>c){
      if(a + b == c)
        cout<<"Case "<<cont<<": "<<a<<"+"<<b<<"="<<c<<endl;
      else if(a == b + c)
        cout<<"Case "<<cont<<": "<<a<<"="<<b<<"+"<<c<<endl;
      else if(a - b == c)
        cout<<"Case "<<cont<<": "<<a<<"-"<<b<<"="<<c<<endl;
      else if(a == b - c)
         cout<<"Case "<<cont<<": "<<a<<"="<<b<<"-"<<c<<endl;
      else if(a * b == c)
         cout<<"Case "<<cont<<": "<<a<<"*"<<b<<"="<<c<<endl;
      else if(a == b * c)
         cout<<"Case "<<cont<<": "<<a<<"="<<b<<"*"<<c<<endl;
      else if(a / b == c)
         cout<<"Case "<<cont<<": "<<a<<"/"<<b<<"="<<c<<endl;
      else if(a == b / c)
         cout<<"Case "<<cont<<": "<<a<<"="<<b<<"/"<<c<<endl;
       cont++;
    }
    return 0;
}
