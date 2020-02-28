#include <bits/stdc++.h>

using namespace std;
 const int MAX=1e6;
 int A[MAX];
//by KmS
 int ta_cycle(int n)
 {   int cont=1;
     while(n!=1){
    if(n%2==0)
        n/=2;
     else
        n=(n*3)+1;
        cont++;
                }
    return cont;

 }


int main()
{
    int a,b;
    int m=0;
    int cy=0;
    //int z=22;
     /*a=ta_cycle(z);
     cout<<a<<endl;*/
     while(cin>>a>>b)
     {
        bool flag = false;
         if(b < a){
            swap(a, b);
            flag = true;
         }

       for(int i=a;i<=b;++i)
       {

         cy=ta_cycle(i);

          if(m<cy)
            m=cy;

        }
        if(flag == false)
            cout<<a<<" "<<b<<" "<<m<<endl;
        else
            cout<<b<<" "<<a<<" "<<m<<endl;
       m=0;

     }
    return 0;
}
