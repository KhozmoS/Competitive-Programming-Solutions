#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;
typedef long long LL;
typedef pair <int , int> par;


par ini , fin;

int mx[] = {0 , 1 , 0 , -1};
int my[] = {1 , 0 , -1 , 0};

char M[MAXN][MAXN];
int t , f , c;
bool mk[MAXN][MAXN];
queue <par> cola;
  bool vale(par nod)
  {
      if((M[nod.first][nod.second] == '.' || M[nod.first][nod.second] == 'b') && nod.first > 0 && nod.first <= f && nod.second > 0 && nod.second <= c && !mk[nod.first][nod.second])
      {
          mk[nod.first][nod.second] = true;
          return true;
      }
      return false;
  }

 bool bfs(par x)
 {
     mk[x.first][x.second] = true;
     cola.push(x);
     while(!cola.empty())
     {
         par n = cola.front();
         cola.pop();
         if(n.first == fin.first && n.second == fin.second)
         return true;

         for(int i = 0 ; i < 4 ; i++)
         {
           par nn;
           nn.first = n.first + mx[i];
           nn.second = n.second + my[i];
           if(vale(nn))
           {
               cola.push(nn);
           }
         }
     }
      return false;
 }

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>f>>c;
        for(int i = 1 ; i <= f ; i++)
        for(int j = 1 ; j <= c ; j++)
        {
            cin>>M[i][j];
            if(M[i][j] == 'g')
            {
                ini.first = i;
                ini.second = j;
            }
            if(M[i][j] == 'b')
            {
                fin.first = i;
                fin.second = j;
            }
        }
          if(bfs(ini))
          cout<<"Good\n";
          else
          cout<<"Bad\n";
     for(int i = 1 ; i <= f ; i++)
     for(int j = 1 ; j <= c ; j++)
     {
       mk[i][j] = false;
     }
    }



    return 0;
}
