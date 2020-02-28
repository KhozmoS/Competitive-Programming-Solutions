#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e6 + 5;
int ar[MAX];
const int MAXN = 1e2 + 5;
bool mk[MAXN][MAXN][MAXN];


int main()
{


   for(int i = 0 ; i <= MAXN ; i++)
      for(int j = 0 ; j <= MAXN ; j++)
         for(int l = 0 ; l <= MAXN ; l++)
         {
         if(!i && !j && !l) continue;
         if(!mk[i][j][l])
         {
             ar[max(max(i , j) , l)]++;
             int x = i + i;
             int y = j + j;
             int z = l + l;
             while(x <= 100 && y <= 100 && z <= 100)
             {
                 mk[x][y][z] = true;
                 x += i;
                 y += j;
                 z += l;
             }
         }
      }

   for(int i = 1 ; i <= 100 ; i++) ar[i] = ar[i] + ar[i - 1];
   int t ; cin>>t;

   for(int cas = 1 ; t-- ; cas++)
   {
       int n; cin>>n;

       cout<<ar[n]<<"\n";
   }
}
/*
4
2
4
5
231

*/
