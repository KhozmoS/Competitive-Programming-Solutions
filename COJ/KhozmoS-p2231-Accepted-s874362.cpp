#include<bits/stdc++.h>
using namespace std;

int main(){
string A,B;
   int contA=0;
   int contB=0;
   int n;
   cin>>n;
      for(int i=0;i<n;i++){
cin>>A>>B;
   if(A[0]=='r'&&B[0]=='s')
      contA++;
   else if(A[0]=='s'&&B[0]=='p')
      contA++;
   else if(A[0]=='p' && B[0]=='r')
      contA++;
   else if(A[0]=='r'&&B[0]=='p')
      contB++;
   else if(A[0]=='s'&&B[0]=='r')
      contB++;
   else if(A[0]=='p'&&B[0]=='s')
      contB++;
      }
    if(contA>contB)
        cout<<"A win"<<endl;
    else if(contA<contB)
        cout<<"B win"<<endl;
    else
        cout<<"tied"<<endl;

return 0;
}
