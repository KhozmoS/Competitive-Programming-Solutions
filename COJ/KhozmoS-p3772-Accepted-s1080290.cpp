#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
     cin>>t;
      while(t--)
      {
       double sum = 0;
       double x;
        for(int i = 0 ; i < 10 ; i++){
           cin>>x;
            sum += x;
          }
        sum *= 0.85;
        printf("%.3lf\n" , sum);
     }
    return 0;
}
