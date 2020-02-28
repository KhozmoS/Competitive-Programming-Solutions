#include<bits/stdc++.h>
using namespace std;
 string sum(string A,string B){
      string sol="";
      int rest=0;
      int suma;
      char agr;
      int ta=A.size();
      int tb=B.size();
       if(ta>=tb){
            int j=tb-1;
        for(int i=ta-1;i>=0;i--){
           suma=0;
           suma+=rest;
           rest=0;
            if(j>=0){
            suma+=(A[i]-'0')+(B[j]-'0');
             if(suma>=10){
                rest+=suma/10;
                suma=suma%10;
             }
             agr=char(suma+48);
             sol=agr+sol;
            }
            else{
            suma=(A[i]-'0')+suma;
            sol=char(suma+48)+sol;}
            j--;
        }
         if(rest!=0)
        sol=char(rest+48)+sol;
       }
       else if(tb>ta){
           int j=ta-1;
          for(int i=tb-1;i>=0;i--){
           suma=0;
           suma+=rest;
           rest=0;
           if(j>=0){
            suma+=(B[i]-'0')+(A[j]-'0');
             if(suma>=10){
               rest+=suma/10;
               suma=suma%10;
             }
             agr=char(suma+48);
             sol=agr+sol;
           }
           else{
                suma=(B[i]-'0')+suma;
                sol=char(suma+48)+sol;}
                j--;
            if(rest!=0)
             sol=char(rest+48)+sol;
          }
       }

     return sol;
    }


int  main(){
  string bas="2";
    int exp;
    cin>>exp;
      for(int i=0;i<exp-1;i++){
        bas=(sum(bas,bas));
      }
        if(exp==0)
            cout<<1<<endl;
        else
      cout<<bas<<endl;
return 0;
}
