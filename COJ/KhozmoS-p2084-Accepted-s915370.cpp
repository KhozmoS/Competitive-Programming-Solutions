#include <bits/stdc++.h>
#define MAXN 105
using namespace std;
int  n , canti;
int may = 0;int men = 101;
int mx[] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
int my[] = {1 , 1 , 0 ,-1 ,-1 , -1 , 0 ,   1};
typedef pair<int , int > par;
queue<par>cola;
char Isl[MAXN][MAXN];
bool mk[MAXN][MAXN];
bool valid(int x , int y)
{
  if(mk[x][y] == false && x >= 0 && y >= 0 && x < n && y < n)
    return true;
    return false;
}
int bfs(int a , int b)
{
  par ini;
      ini.first = a;
      ini.second = b;
      int cont = 0;
      mk[a][b] = true;
      cola.push(ini);
       while(!cola.empty())
       {
         par pos = cola.front();
         cola.pop();
         cont++;
         for(int i = 0 ; i < 8 ; i++)
         {
           par nue;
           nue.first = pos.first + mx[i];
           nue.second = pos.second + my[i];
           if(valid(nue.first , nue.second) && Isl[nue.first][nue.second] == 'l')
           {
             mk[nue.first][nue.second] = true;
             cola.push(nue);
           }
         }
       }
       return cont;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   while(1)
   {
       cin>>n;
       if(n == 0)
        break;
       for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
         cin>>Isl[i][j];
       for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
          if(Isl[i][j] == 'l' && mk[i][j] != true){
            int comp = bfs(i , j);canti++;
            if(may < comp)
             may = comp;
            if(men > comp && comp != 0)
             men = comp;
          }
          if(men == 101)
          cout<<canti<<" "<<0<<" "<<may<<"\n";
          else
          cout<<canti<<" "<<men<<" "<<may<<"\n";
          //LIMPIAR
          canti = 0; men = 101; may = 0;
          for(int i = 0 ; i < n ; i++)
           for(int j = 0 ; j < n ; j++)
            mk[i][j] = false;
   }
    return 0;
}
