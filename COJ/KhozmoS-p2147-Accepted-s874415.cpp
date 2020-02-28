#include<bits/stdc++.h>
using namespace std;

int main(){
  string cad;

  int mov,n;
   cin>>n;
    for(int i=0;i<n;i++){
  cin>>cad>>mov;
  string cad1="";
  int ta=cad.size();
    int pos=ta-1;
   for(int i=0;i<mov;i++){
     cad1=cad[pos]+cad1;
     pos--;
     if(cad1==cad){
        cad1="";
        pos=ta-1;
     }
    }
    int ta1=cad1.size();
    for(int i=0;i<ta-ta1;i++)
        cad1+=cad[i];
        cout<<cad1<<endl;
    }
return 0;
}
