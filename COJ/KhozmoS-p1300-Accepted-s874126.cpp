#include <bits/stdc++.h>

using namespace std;
  const int MAX=42;
  bool A[MAX];
int main()
{
   int n;
   for(int i=0;i<10;i++){
      cin>>n;
      A[n%42]=true;
   }
   int cont=0;
   for(int i=0;i<MAX;i++)
   {
      if(A[i]==true)
           cont++;
   }
    cout<<cont<<endl;
    return 0;
}
