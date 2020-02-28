#include <bits/stdc++.h>
int h1,sol,m1,h2,m2;
using namespace std;
 int main()
{
     int total = 1440;
  while(true){
    cin>>h1>>m1>>h2>>m2;
      if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
        break;
      if(h1 > h2){
        sol = (total - ((h1 * 60) + m1)) + (h2 * 60) + m2;
      cout<<sol<<endl;
      }
      else if(h1 == h2 && m1 > m2){
        sol = (total - ((h1 * 60) + m1)) + (h2 * 60) + m2;
       cout<<sol<<endl;
      }
       else if(h2 > h1){
         sol = ((h2 - h1) * 60) + m2 - m1;
         cout<<sol<<endl;
       }
       else if(h1 == h2 && m1 < m2){
         cout<<m2 - m1<<endl;
       }
       else
        cout<<0<<endl;


  }

    return 0;
}
