#include<bits/stdc++.h>
using namespace std;
 float a;
 float suma;
int main(){
    float n = 2;
    int cards = 0;
  while(true){
     cin>>a;
       if(a == 0.00)
        break;
     while(suma < a)
     {
         suma += 1 / n;
         n++;
         cards++;
     }
        cout<<cards<<" card(s)"<<endl;
        suma = 0;
        n = 2;
        cards = 0;

  }
return 0;
}
