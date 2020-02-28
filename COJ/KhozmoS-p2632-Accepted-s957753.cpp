#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
const int cast = 97;

int ar[MAXN][MAXN] , br[MAXN][MAXN] ,arr[MAXN][MAXN];
int suma , sumb;


int main()
{
//    generar();
  ios_base::sync_with_stdio(0);cin.tie(0);

   int n , x;
   cin>>n;
   for(int i = 1 ; i <= n ; i++)
   for(int j = 1 ; j <= i ; j++)
   {

   cin>>x;
   //arr[i][j] = x;
   ar[i][j] = x;
   br[i][j] = x * x;
   }
   for(int i = 1 ; i <= n ; i++){
   for(int j = 1 ; j <= i ; j++){
   br[i][j] += max(br[i - 1][j] , br[i - 1][j - 1]);
   ar[i][j] += max(ar[i - 1][j] , ar[i - 1][j - 1]);
   }
   }

   for(int j = 1 ; j <= n ; j++)
   {
    if(ar[n][j] > suma)
    suma = ar[n][j];
    if(br[n][j] > sumb)
    sumb = br[n][j];
   }
/*   for(int i = 1 ; i <= n ; i++){
   for(int j = 1 ; j <= i ; j++)
   cout<<br[i][j]<<" ";
   cout<<"\n";
   }*/
   //cout<<"\n";
   cout<<sumb<<' '<<suma<<"\n";
   cout<<char((sumb % 26) + cast)<<char((suma % 26) + cast)<<"\n";

    return 0;
}
