#include<bits/stdc++.h>
using namespace std;
  int N,a,sol,n;
  int US(int a)
  {
    while(a >= 10)
    {   n = a;
        sol = 0;
        while(n != 0 )
        {
          sol += n % 10;
          n /= 10;
        }
        a = sol;
    }
    return a;
  }

int main()
{
    string num;
    cin>>N;
     for(int i = 0;i < N; i++){
     cin>>num;
      for(int j = 0; j < num.size();j++){
        a += ( num[j] - '0' );
      }
   sol = US(a);
   cout<<sol<<endl;
    a = 0;
     }
    return 0;
}
