#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 105;
typedef pair < int , int > par;

int mx[] = {-1 , -1 , 0, 1 , 1 , 1 , 0 , -1};
int my[] = {0 ,  1 , 1 , 1 , 0 , -1 , -1 , -1 };

int N , M , x , y;
char field[MAXN][MAXN];

int cost[MAXN][MAXN];

queue<par> cola;

int bfs(int a , int b)
{
  int sol = -1;
  //cost[a][b];
  par nod;
  nod.first = a;
  nod.second = b;
  cola.push(nod);
  field[a][b] = '*';
  while(!cola.empty())
  {
    par n = cola.front();
    cola.pop();
    for(int i = 0 ; i < 8 ; i++)
    {
       par nn;
       nn.first = n.first + mx[i];
       nn.second = n.second + my[i];
       if(field[nn.first][nn.second] != '*' )
       {
          field[nn.first][nn.second] = '*';
          cost[nn.first][nn.second] = (cost[n.first][n.second] + 1);
          if(cost[nn.first][nn.second] > sol)
          sol = cost[nn.first][nn.second];
          cola.push(nn);
       }
     }
  }
  return sol;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>N>>M>>x>>y;
     swap(N , M);
     swap(x , y);
     for(int i = 0 ; i < MAXN ; i++)
     for(int j = 0 ; j < MAXN ; j++)
     field[i][j] = '*';

     for(int i = 1 ; i <= N ; i++)
     for(int j = 1 ; j <= M ; j++)
     {
         cin>>field[i][j];
     }
     cout<<bfs( N - x + 1 , y)<<"\n";
    return 0;
}
