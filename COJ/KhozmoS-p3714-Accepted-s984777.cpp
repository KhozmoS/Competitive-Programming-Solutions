#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;
  int cont = 1;

 string cad;
 string sol;

 bool comp[MAXN];
 int Arr[MAXN];

  string conv(int n)
  {
      string ret = "";
      while(n != 0)
      {
          int p = n % 10;
          n /= 10;
          ret = char(p + 48) + ret;
      }
      return ret;
  }
   string solar(string a)
   {
      for(int i = 0 ; i < a.size() ; i++)
      {
          if(a[i] == '2')
          {
              a[i] = '5';
          }
          else if(a[i] == '5')
          a[i] = '2';
          else if(a[i] == '6')
          a[i] = '9';
          else if(a[i] == '9')
          a[i] = '6';
      }
      return a;
   }
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

        //cout<<conv(4);
        while(cin>>cad){

        for(int i = 0 ; i < cad.size() ; i++)
        {
           if(!comp[cad[i] - 'a']){

              comp[cad[i] - 'a'] = true;
              Arr[cad[i] - 'a'] = cont;
              sol += conv(cont);
              cont++;
           }
           else
           {
            int num = Arr[cad[i] - 'a'];
            sol += conv(num);
           }
        }
             sol = solar(sol);
             cout<<sol<<"\n";
             //LIMPIAR
             for(int i = 0 ; i < 100 ; i++)
             {
                 Arr[i] = 0;
                 comp[i] = false;
             }
             sol = "";
             cont = 1;
         }
    return 0;
}
