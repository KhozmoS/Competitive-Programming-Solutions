#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
int n;
cin>>n;
   for(int i=0;i<n;i++){
int cont=0;
  cin>>a>>b>>c;
  int numb=a+b;
   if(numb==0||c==1){
    cout<<0<<endl;
     continue;
     }
   while(numb>=c){
    cont+=numb/c;
    numb=numb/c+(numb%c);
     }
  cout<<cont<<endl;
   }
return 0;
}
