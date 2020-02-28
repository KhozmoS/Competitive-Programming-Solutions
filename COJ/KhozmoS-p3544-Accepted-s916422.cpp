#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef pair <int , int> par;
int M , N , t;
int mx[] = {0 , 1 , 0 , -1};
int my[] = {1 , 0 , -1 , 0};
char A[MAXN][MAXN];
int cost[MAXN][MAXN];
bool mk[MAXN][MAXN];
queue<par>cola;
par ini;
bool vale (int x , int y)
{
    if(!mk[x][y] && A[x][y] == '.' && x >= 0 && x < N  && y >= 0 &&  y < M)
     {
         mk[x][y] = true;
         return true;
     }
     return false;
}
par bfs ( par n)
{
    par sol;
    int may = -1;
    cola.push(n);
    mk[n.first][n.second] = true;
    while(!cola.empty())
    {
        par p = cola.front();
        cola.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            if(vale(p.first + mx[i] , p.second + my[i]))
            {
                par pp ;
                pp.first =  p.first + mx[i];
                pp.second = p.second + my[i];
                cola.push(pp);
                cost[pp.first][pp.second] = cost[p.first][p.second] + 1;
                if(may < cost[pp.first][pp.second])
                {
                    may = cost[pp.first][pp.second];
                    sol.first = pp.first;
                    sol.second = pp.second;
                }
            }
        }
    }
    return sol;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
    while(t--)
    {
       cin>>M>>N;
       int cont = 0;
       for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
         cin>>A[i][j];
         if(cont == 0 && A[i][j] == '.')
         {
             cont++;
             ini.first = i;
             ini.second = j;
         }
        }}
        par x = bfs(ini);
       // cout<<x.first<<" "<<x.second<<"\n";
        //LIMPIAR
        for(int i = 0 ; i < N ; i ++){
         for(int j = 0 ; j < M ; j++){
            mk[i][j] = 0; cost[i][j] = 0;}}
        par sol = bfs(x);
        cout<<"Maximum rope length is "<<cost[sol.first][sol.second]<<"."<<"\n";
        //LIMPIAR
        for(int i = 0 ; i < N ; i ++){
         for(int j = 0 ; j < M ; j++){
            mk[i][j] = 0; cost[i][j] = 0;}}
    }
    return 0;
}
/*3
3 4
###
#.#
#.#
#.#
8 7

########
#.#....#
#.#.####
#.....##
#####.##
###...##
########
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######
*/
