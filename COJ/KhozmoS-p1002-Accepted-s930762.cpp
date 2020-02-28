#include <bits/stdc++.h>

using namespace std;
const int MAXN = 14;

int t;
int MA[MAXN][MAXN], TA[MAXN][MAXN];
int N;char a;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>t;
   while(t)
   {
      cin>>N;
      bool ok = false;
      for(int i = 1 ; i <= N ; i++)
      {for(int j = 1 ; j <= N ; j++){
          cin>>a;
          if(a == '.'){MA[i][j]++; ok = true;}
          TA[i][j] = (TA[i - 1][j] + TA[i][j - 1]) - TA[i - 1][j - 1] + MA[i][j];
      }
      }
    if(!ok)cout<<0<<"\n";
    else{
   int ini = 1; int fin = N; int rev;
   while((fin - ini) > 3)
   {
       rev = (ini + fin) / 2;
       bool flag = false;
       for(int i = 1 ; i + (rev - 1) <= N ; i++){
         for(int j = 1 ; j + (rev - 1)<= N ; j++)
         {
             int k = rev + i - 1; int l = rev + j - 1;
             int sum = (TA[k][l] - TA[i - 1][l]) - TA[k][j - 1] + TA[i - 1][j - 1];
             if(sum == (rev * rev))
             flag = true;
         }
         if(flag)break;
       }
       if(flag)
       ini = rev;
       else fin = rev;
   }
   int sol;bool flag = false;
    while(fin)
    {
        int rev = fin;
       for(int i = 1 ; i + (rev - 1) <= N ; i++){
         for(int j = 1 ; j + (rev - 1)<= N ; j++)
         {
             int k = rev + i - 1; int l = rev + j - 1;
             int sum = (TA[k][l] - TA[i - 1][l]) - TA[k][j - 1] + TA[i - 1][j - 1];
             if(sum == (rev * rev)){
             flag = true;
             sol = rev;
             }
         }
         if(flag)break;
       }
       if(flag)break;
       fin--;
    }
   cout<<sol<<"\n";
    }
   //LIMPIAR
   for(int i = 0 ; i <= N ; i++){
   for(int j = 0 ; j <= N ; j++){
   TA[i][j] = 0;MA[i][j] = 0;
   }
   }
   t--;
   }
    return 0;
}
