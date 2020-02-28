#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <memory.h>
int const MAX = 11;
int const INTEGER_MAX_VALUE = 2147483647;

using namespace std;
long long  i, j,  n,h, m, test, city, f, c, w, u, min1, v, newLength,
		cont,cont1;

int res,temp, temp1,a, b;
bool flag;
set<int> ss;
set<int>::const_iterator ite,ite2;


//char  elements[MAX][MAX];

//int  mat[31]={0,0,3,0,11,0,41,0,153,0,571,0,2131,0,7953,0,29681,0,110771,0,413403,0,1542841,0,5757961,0,21489003,0,80198051,0,299303201};

int gcd(int a,int b){
   if(!b)
     return a;
   return gcd(b,a%b);
}


int main() {
  cin>>n;
  while (n) {
   flag = 0;
   //cont1++;

   if(n==2147483647 || n ==-2147483647)
   cont = 1;
   else{
   flag = n>0?0:1;
   n = flag?n*(-1):n;
   ss.clear();
   cont = 0;
   while(n % 2 == 0){
      cont ++;
      n = n/2;
   }
   if (cont)
     ss.insert(cont);
   i = 3;
   cont = 0;
   while(i*i <=n){
      if(n % i == 0){
        cont ++;
        n = n/i;
      }else{
        if (cont){
          ss.insert(cont);
        }
        cont = 0;
        i+=2;
      }
   }
   if(n > 1 ){
      if(n % i == 0){
         cont++;
         ss.insert(cont);
         //ite2 = ss.end();ite2--;
        if(ss.size()==1){
          ite = ss.begin();
          cont = *ite;
        }else{
          ite = ss.begin();
          cont =*ite;ite++;
          for(;ite!=ss.end();ite++){
           cont = gcd(cont,*ite);
           if(cont == 1)
            break;
          }
        }
      }else{
       cont = 1;
      }
   } else{
         ite = ss.begin();
          cont = *ite;
   }



 }
   if(flag){
      while(cont%2==0)
        cont/=2;
   }
   cout<<cont<<"\n";
   cin>>n;

}
 return 0;
}