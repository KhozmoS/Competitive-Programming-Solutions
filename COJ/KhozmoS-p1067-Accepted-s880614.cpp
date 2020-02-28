#include <bits/stdc++.h>

using namespace std;
  int a;
  int tl = 0;
  int th = 11;
  string cad,cad1;
int main()
{
      while(true)
      {

        cin>>a;
          if(a == 0)
              break;
        cin>>cad;
        cin>>cad1;
          if(cad1 == "high"){
            if(th > a)
              th = a;
              }
           else if(cad1 == "low"){
             if(tl < a)
              tl = a;
           }
           else{
            if(a > tl && a < th)
               cout<<"Stan may be honest"<<endl;
             else
               cout<<"Stan is dishonest"<<endl;
               th = 11;
               tl = 0;
           }

      }

    return 0;
}
