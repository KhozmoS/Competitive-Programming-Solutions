#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8;

int n;

int sol = 0;
int mx[] = {-1 , 0 , 1 , 0};
int my[] = {0 , 1 , 0 , -1};

char M[MAXN][MAXN];
bool mk[MAXN][MAXN];

void dfs(int x , int y , int cantp , int cants , int c)
{
    if(cantp == cants)
    {
     sol = max(sol , cantp + cants);
     return;
    }
    if(cantp > ((n * n) / 2))
        return;

    for(int i = 0 ; i < 4 ; i++)
    {
      int movx = x + mx[i];
      int movy = y + my[i];
      if(movx > 0 && movy > 0 && movx <= n && movy <= n && !mk[movx][movy])
      {
        mk[movx][movy] = true;

        if(M[movx][movy] == '('){
         if(!c)
          dfs(movx , movy , cantp + 1 , cants , 0);
        }
        else
          dfs(movx , movy , cantp , cants + 1, 1);

        mk[movx][movy] = false;
      }
    }
    return;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ;j++)
    {
       cin>>M[i][j];
    }
    mk[1][1] = true;
    dfs(1 , 1 , 1 , 0 , 0);

    if(M[1][1] == ')')
       cout<<0<<"\n";
    else
       cout<<sol<<"\n";


    return 0;
}
