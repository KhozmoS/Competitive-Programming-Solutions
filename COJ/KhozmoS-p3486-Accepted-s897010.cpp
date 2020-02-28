#include<bits/stdc++.h>

using namespace std;
 char n;
 string SOD[9][9];
 string comp = "123456789";
 string cad;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
     for(int i = 0;i < 9;i++){
        for(int j = 0; j < 9 ;j++){
         do{
            cin>>n;
         }while(n == '|' || n == '+' || n == '-');
          SOD[i][j] = n;
      }
     }
      bool flag = false;
      for(int i = 0; i < 9 ; i++){
            cad = "";
       for(int j = 0 ; j < 9 ; j++){
        cad += SOD[i][j];
       }
       sort(cad.begin(),cad.end());
         if(cad != comp){
           flag = true;
           break;
         }
      }
       if(flag){
        cout<<"WRONG"<<"\n";
       }
       else
        cout<<"CORRECT"<<"\n";

    return 0;
}
