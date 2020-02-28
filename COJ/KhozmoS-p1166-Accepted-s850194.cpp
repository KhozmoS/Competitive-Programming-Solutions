#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
    int A[101];
    int cont=0;
    int a;
    for(int i=0;i<n;++i)
    {
      cin>>a;
      for(int e=0;e<a;++e)
       {
         cin>>A[e];
          if(A[e]%2==0)
          {
              cont++;
          }
        }
       int par=cont;
       int impar=a-par;
       cout<<par<<" even and "<<impar<<" odd."<<endl;
       cont=0;
    }


    return 0;
}