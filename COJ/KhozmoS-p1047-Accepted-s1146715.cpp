#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e6 + 5;
int ar[MAX];
const int MAXN = 1e3 + 5;
bool mk[MAXN][MAXN];


int main()
{


   for(int i = 1 ; i <= MAXN ; i++)
      for(int j = 1 ; j <= MAXN ; j++)
      {
         if(!mk[i][j])
         {
             ar[max(i , j)]++;
             int x = i + i;
             int y = j + j;
             while(x <= 1000 && y <= 1000)
             {
                 mk[x][y] = true;
                 x += i;
                 y += j;
             }
         }
      }
   ar[1] += 2;
   for(int i = 1 ; i <= 1000 ; i++) ar[i] = ar[i] + ar[i - 1];
   int t ; cin>>t;

   for(int cas = 1 ; t-- ; cas++)
   {
       int n; cin>>n;

       cout<<cas<<" "<<n<<" "<<ar[n]<<"\n";
   }
}
/*
4
2
4
5
231

*/
