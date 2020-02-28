#include<bits/stdc++.h>
using namespace std;
 long long n;
 string sol,com;
  string bin (long long n)
  {
      sol = "";
     while(n >= 1)
     {
        if(n % 2 == 0)
         sol = '0' + sol;
        else
         sol = '1' + sol;
         n /= 2;
     }
     return sol;
  }
int main()
{
    int N;
    cin>>N;
     for(int i = 0; i < N ; i++)
     {
        cin>>n;
        sol = bin(n);
        com = sol;
        reverse(sol.begin(),sol.end());
         if(com == sol)
            cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;
     }

   return 0;
}
