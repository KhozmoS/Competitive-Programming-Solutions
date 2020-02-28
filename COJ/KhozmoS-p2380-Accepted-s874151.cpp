#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a;
int sol=0;
cin>>n;
  for(int i=0;i<n;i++){
 cin>>a;
     while(a!=0){
      if(a%2==1)
       sol+=1;
       a/=2;
     }
       }
     cout<<sol<<endl;
return 0;
}
