#include<bits/stdc++.h>
#define MAXN 100
using namespace  std;
typedef pair <int , int > par;
char M [MAXN][MAXN];
int N;
queue<par>cola;
par beg;
par fin;
int cost[MAXN][MAXN];
int cx[] = {0 , 1 , 0 , -1};
int cy[] = {1 , 0 , -1 , 0};
bool valid(int x ,int y)
 {
     if(M[x][y] != '*' && x < N && x >= 0 && y < N && y >= 0)
        return true;
     return false;
 }
int bfs()
{
    //fill(cost , cost + (N + 1), 0 );
    cost[beg.first][beg.second] = 0;
    cola.push(beg);
    M[beg.first][beg.second] = '*';
    while(!cola.empty())
    {
       par pos = cola.front();
       cola.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            par nue;
                nue.first = pos.first + cx[i];
                nue.second = pos.second + cy[i];
           if(valid(pos.first + cx[i] , pos.second + cy[i]))
           {
               if(cost[pos.first + cx[i]][pos.second + cy[i]] == 0)
                  cost[pos.first + cx[i]][pos.second + cy[i]] = cost[pos.first][pos.second] + 1;
               else if(cost[pos.first + cx[i]][pos.second + cy[i]] > cost[pos.first][pos.second] + 1)
                  cost[pos.first + cx[i]][pos.second + cy[i]] = (cost[pos.first][pos.second] + 1);
                cola.push(nue);
                M[nue.first][nue.second] = '*';
           }
        }


    }
    if(cost[fin.first][fin.second] != 0)
    return cost[fin.first][fin.second];
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>N;
   for(int i = 0 ; i < N ; i++)
   for(int j = 0 ; j < N ; j++){
      cin>>M[i][j];
       if(M[i][j] == 'm'){
         beg.first = i;
         beg.second = j;}
       else if(M[i][j] == '#'){
         fin.first = i;
         fin.second = j;
       }
   }
    if(bfs() == -1)
     cout<<"-1"<<"\n";
    else
     cout<<bfs()<<"\n";


    /*for(int i = 0 ; i < N ; i++){
      for(int j = 0 ; j < N ; j++)
        cout<<cost[i][j];
        cout<<"\n";
    }*/


return 0;
}


