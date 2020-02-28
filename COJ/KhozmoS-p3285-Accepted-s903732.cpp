#include <bits/stdc++.h>

using namespace std;
long long n;
string cad , sol;
int ta , cont;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
      while(t--){
     cin>>n;
    cin>>cad;
    ta = cad.size();
      if(ta < n)
      {
          n = n % ta;
          int i = ta - 1;
          for(cont = 0 ; cont < n ; cont++)
          {
              sol = cad[i] + sol;
              i--;
          }
          for(int i = 0 ; i < ta - n ; i++)
          {
              sol += cad[i];
          }
          cout<<sol<<"\n";
      }
      else if(ta == n)
      {
          cout<<cad<<"\n";
      }
      else
      {
          int i = ta - 1;
          for(cont = 0 ; cont < n ; cont++)
          {
              sol = cad[i] + sol;
              i--;
          }
          for(int i = 0 ; i < ta - n ; i++)
          {
              sol += cad[i];
          }
          cout<<sol<<"\n";
      }
      //limpiar
      cont = 0;
      sol = "";
      }
    return 0;
}
