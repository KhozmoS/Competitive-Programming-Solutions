#include <bits/stdc++.h>

using namespace std;
const int MAXN = 111;

typedef pair <int , int> par;

int f , c , k;

int mx[] = {0 , 1 , 0 , -1};
int my[] = {1 , 0 , -1 , 0};
 queue<par> cola;
 char granja[MAXN][MAXN];
 int bfs(int i , int j)
 {
     par nod;
     int cont = 0;

     nod.first = i;
     nod.second = j;
     cola.push(nod);
     granja[i][j] = '.';
     while(!cola.empty())
     {
         par n = cola.front();
         cola.pop();
         cont ++;
         for(int k = 0 ; k < 4 ; k++)
         {
             par nn;
             nn.first = n.first + mx[k];
             nn.second = n.second + my[k];
             if(granja[nn.first][nn.second] == '#')
             {
                 cola.push(nn);
                 granja[nn.first][nn.second] = '.';
             }
         }

     }
     return cont;
 }

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < MAXN ; i++)
    for(int j = 0 ; j < MAXN ; j++)
    granja[i][j] = '.';


   cin>>f>>c>>k;

    while(k--)
    {
      int x , y; cin>>x>>y;

      granja[x][y] = '#';
    }
    int sol = 0;
	for(int i = 1 ; i <= f ; i++)
	for(int j = 1 ; j <= c ; j++)
	{
	    if(granja[i][j] == '#')
	    sol = max(sol , bfs(i , j));
	}
	cout<<sol<<"\n";
	return 0;
}
