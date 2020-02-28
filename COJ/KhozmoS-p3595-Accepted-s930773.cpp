#include <bits/stdc++.h>

using namespace std;
 const int MAXN = 1005;
 int MA[MAXN][MAXN];
 int TA[MAXN][MAXN];
int cont[MAXN];
 int N;
 int posi , posj;
int main()
{
    bool ok = false;
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>N;
   for(int i = 1 ; i <= N ; i++){
   for(int j = 1 ; j <= N ; j++){
     cin>>MA[i][j];
     if(MA[i][j] == 1)
     ok = true;
     TA[i][j] = (TA[i - 1][j] + TA[i][j - 1]) - TA[i - 1][j - 1] + MA[i][j];
   }
   }
  /* for(int i = 1 ; i <= N ; i++){
   for(int j = 1 ; j <= N ; j++)
   cout<<TA[i][j]<<" ";
   cout<<"\n";
   }*/
   if(!ok){
     cout<<0<<"\n";
    //cout<<"shit\n";
    }
    else{
     bool flag = false;int res;
    int ini = 1; int fin = N;
    while((fin - ini) > 3)
    {
       res = (ini + fin) / 2;
       for(int i = 1 ; i <= N ; i++)
       {for(int j = 1 ; j <= N ; j++)
       {
         int k = (res - 1) + i;
         int l = (res - 1) + j;
         int sum = ((TA[k][l] - TA[i - 1][l]) - TA[k][j - 1]) + TA[i - 1][j - 1];
         if(sum == (res * res))
         {
           //ini = rev;
           flag = true;
           break;
         }
         //else fin = rev;
       }
        if(flag)
        break;
       }
       if(flag)
       ini = res;
       else fin = res;
    }
   int  p = 1;
   //cout<<may * c ont[may]<<"\n";
    //rev = ini;
    int rev = 0;
    while(fin){
        bool ya = false;
         rev = fin;
   for(int i = 1 ; i + (rev - 1) <= N ; i++){
   for(int j = 1 ; j + (rev - 1) <= N ; j++){
         int k = (rev - 1) + i;
         int l = (rev - 1) + j;
         int sum = ((TA[k][l] - TA[i - 1][l]) - TA[k][j - 1]) + TA[i - 1][j - 1];
         //cout<<p++<<")"<<sum<<" "<<rev<<"\n";
         if(sum == (rev * rev))
         {
           cont[rev]++;
           ya = true;
         }
   }
   }
    if(ya)
    break;
   fin--;
    }
   // cout<<rev<<" "<<cont[rev]<<"\n";
   cout<<rev * cont[rev]<<"\n";
   }
    return 0;
}
