#include <bits/stdc++.h>

using namespace std;
  const int MAXN = 33;

  int alph[MAXN];
  int t , n;
  string cad;

int main()
{
   // cout<<char(1 + 'A');
    ios_base::sync_with_stdio(0);cin.tie(0);

     cin>>t;

      while(t--)
      {
          cin>>n;
          cin>>cad;
          for(int i = 0 ; i < n ; i++)
          {
              alph[cad[i] - 'A']++;
          }

          bool flag = false;
          string pal = "";
          string pegar = "";

          for(int i = 0 ; i < 26 ; i++)
          {
              if(alph[i] != 0 && alph[i] % 2 == 0)
              {
                 for(int j = 0 ; j < alph[i] / 2 ; j++)
                 pal += char(i + 'A');
              }
              else if(alph[i] != 1 && alph[i] % 2 == 1 && !flag)
              {
                  flag = true;
                  pegar = char(i + 'A');
                  alph[i]--;
                  i--;
              }
              else if(alph[i] != 1 && alph[i] % 2 == 1)
              {
              alph[i]--;
              i--;
              }
              else if(alph[i] == 1 && flag == false)
              {
               flag = true;
               pegar = char(i + 'A');
              }
          }
          string pal1 = pal;
          reverse(pal1.begin() , pal1.end());
          pal += pegar;
          pal += pal1;
          cout<<pal<<"\n";
          //LIMPIAR
          for(int i = 0 ; i < 26 ; i++)
          alph[i] -= alph[i];

      }

    return 0;
}
