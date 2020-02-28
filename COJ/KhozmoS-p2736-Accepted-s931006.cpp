#include<bits/stdc++.h>

using namespace std;
typedef pair<string , int> par;

vector <par> v;
string to_binary(int x)
{
    string cad = "";
    if(x == 0) return "0";
    while(x > 1)
    {
        if(x % 2 == 1)
        cad  ='1' + cad;
        else
        cad = '0' + cad;
        x /= 2;
    }
    cad = '1' + cad;
    //reverse(cad.begin() , cad.end());
    return cad;
}
void tabla()
 {
    for(int i = 0 ; i <= 10000 ; i++)
    {
        int cont = 0;
        par p;
        p.first = to_binary(i);
        for(int i = 0 ; i < p.first.size() ; i++)
        if(p.first[i] == '1')
        cont++;
        p.second = cont;
        v.push_back(p);
    }
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   //cout<<to_binary(9);
   tabla();
   // for(int i = 0 ; i <= 31 ; i++)
  //cout<<to_binary(100000004)<<"\n";
  string s;
  cin>>s;
  cout<<s<<"\n";
   int cont = 0;
   for(int i = 0 ; i < s.size() ; i++)
   {
       if(s[i] == '1')
       cont++;
   }
  // cout<<cont<<"\n";
    while(cont > 1)
    {

          if(cont <= 10000)
          {
              cout<<v[cont].first<<"\n";
              cont = v[cont].second;
          }
          else{
        string cad = to_binary(cont);
         cont = 0;
        cout<<cad<<"\n";
        for(int i = 0 ; i < cad.size() ; i++)
         {
         if(s[i] == '1')
         cont++;
         }
          }
    }
    return 0;
}
