#include<bits/stdc++.h>

 using namespace std;
 int solm , may , men;
  int mcm(int a , int b)
  {
      if(a > b){
        may = a;
        men = b ;
      }
      else{
        may = b;
        men = a;
      }
      if(may % men == 0)
        return men;
       for(int i = men / 2 ; i > 1 ; i--)
          {
              if(men % i == 0 && may % i == 0)
                return i;
          }
     return 1;
  }

 int main()
 {
     int a , l;
     int t;
     cin>>t;
     while(t--){
     cin>>a>>l;
     if(a == l)
        cout<<4<<"\n";
     else{
     int m = mcm(a , l);
     //cout<<m<<endl;
     cout<<((((a / m) + 1) * 2) + (((l / m) + 1) * 2)) - 4<<"\n";
     }
     }
     return 0;
 }
