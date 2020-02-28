#include <bits/stdc++.h>

using namespace std;
  bool coprimes(int a,int b){
      bool sol=false;
      int c;
      for(int i=1;i<=b;i++){
       if(a%i==0 && b%i==0)
        c=i;
      }
        if(c == 1)
         sol=true;
         else
         sol=false;
  return sol;
  }
int main()
{
    int contc=0;
    int a;
    scanf("%d",&a);
      for(int i=1;i<=a;i++){
        if(coprimes(a,i)==true)
          contc++;
        }
    cout<<contc<<endl;

    return 0;
}
