#include<bits/stdc++.h>
using namespace std;
  int n,n1,n2,a,b,sol,N;
int main()
{
      cin>>N;
        for(int i = 0;i < N; i++)
        {
            cin>>a>>b;
             for(n = a;n <= b; n++)
             {
                 n1= n + 1; n2 = n + 2;
                 sol += ((n % 100) * (n1 % 100) * (n2 % 100) % 100) ;
             }
             cout<<sol % 100<<endl;
             sol = 0;
        }
    return 0;
}
