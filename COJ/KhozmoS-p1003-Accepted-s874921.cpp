#include<bits/stdc++.h>
using namespace std;
int maysol,a,n,suma,sol;

int main (){
  int can,vot;
     cin>>n;
     for(int x=0;x<n;x++){
  cin>>can>>vot;

     int X[can][vot];
     for(int j=0;j<vot;j++){
        for(int i=0;i<can;i++){
           cin>>a;
           X[i][j]=a;
        }

     }
       for(int i=0;i<can;i++){
        for(int j=0;j<vot;j++){
           suma+=X[i][j];
        }
           if(suma>maysol){
            maysol=suma;
            sol=i+1;
           }
         suma=0;
     }
      cout<<sol<<endl;
      sol=0;
      maysol=0;
     }
  return 0;
}
