#include<bits/stdc++.h>
using namespace std;

int main(){
  string A;
  while(cin>>A){
        int cont=0;
        int suma=0;
    int ta=A.size();
       if(A[0]=='-')
        for(int i=1;i<ta;i++)
          suma+=A[i]-'0';
        else
     for(int i=0;i<ta;i++)
        suma+=A[i]-'0';

        if(suma % 3 == 0 && (A[ta-1]-'0') % 2==0 && suma % 6==0)
           cont ++;
           for(int i=0;i<ta;i++)
           if(A[i]=='6'){
              cont++;
              break;
              }
              if(cont==2)
                cout<<"EVIL"<<endl;
              else
                cout<<"GOOD"<<endl;
        }

return 0;
}
