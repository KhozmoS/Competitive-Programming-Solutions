#include <bits/stdc++.h>

using namespace std;


map <string , int> mapa;
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
    const int MAXN = 4905;
string ar[100005];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string pow2 = "2";
    ar[0] = "1"; int t;

     for(int i = 1 ; i < MAXN; i++)
      {
        ar[i] = sum(ar[i - 1] , pow2);
        pow2 = sum(pow2 , pow2);
      }


      cin>>t;
       while(t--){

    string x;
    cin>>x;
     bool flag = false;
      for(int i = 0 ; i < MAXN ; i++)
      if(ar[i] == x)
      flag = true;

      if(flag)
       cout<<"NO\n";
      else
        cout<<"YES\n";

       }

    return 0;
}
