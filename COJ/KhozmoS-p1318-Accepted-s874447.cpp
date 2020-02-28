#include<bits/stdc++.h>
using namespace std;
 const int MAX = 3;
 int Arr[MAX];
int main(){
int a;
int may=-1;
int men=1000;
int med=0;
string ORD;
  for(int i=0;i<MAX;i++)
  {
    cin>>a;
    Arr[i]=a;
  }
    for(int i=0;i<MAX;i++){
      if(may<Arr[i])
         may=Arr[i];
    }
    for(int i=0;i<MAX;i++){
       if(men>Arr[i] )
            men=Arr[i];
    }
    for(int i=0;i<MAX;i++){
        if(Arr[i]!=may && Arr[i]!=men )
            med=Arr[i];
    }
    cin>>ORD;
     if(ORD=="ABC")
        cout<<men<<" "<<med<<" "<<may<<endl;
     else if(ORD=="ACB")
        cout<<men<<" "<<may<<" "<<med<<endl;
     else if(ORD=="BAC")
        cout<<med<<" "<<men<<" "<<may<<endl;
     else if(ORD=="BCA")
        cout<<med<<" "<<may<<" "<<men<<endl;
     else if(ORD=="CAB")
        cout<<may<<" "<<men<<" "<<med<<endl;
     else if(ORD=="CBA")
        cout<<may<<" "<<med<<" "<<men<<endl;
return 0;
}
