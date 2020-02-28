#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

bool mrk[MAX][MAX];
bool mk[MAX][MAX];

int mx[] = {-1 , 0 , 1 , 0};
int my[] = {0 , 1 , 0 , -1};
int sol;
int F , C;
int M[MAX][MAX];

void dfs(int x , int y , int cont , int ant)
{
  if(cont > sol)
  sol = cont;

  for(int i = 0 ; i < 4 ; i++)
  {
    int x1 = x + mx[i];
    int y1 = y + my[i];
    if(x1 < F && x1 >= 0 && y1 < C && y1 >= 0 && !mk[x1][y1] && M[x][y] < M[x1][y1])
    {
     mk[x1][y1] = true;
     dfs(x1 , y1 , cont + 1 , M[x1][y1]);
     mk[x1][y1] =  false;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;string cad;
   cin>>t;
    while(t--)
    {
     cin>>cad>>F>>C;

     for(int i = 0 ; i < F ; i++)
      for(int j = 0 ; j < C ; j++){
        cin>>M[i][j];
        mk[i][j] = false;
      }

      sol = 0;
      for(int i = 0 ; i < F ; i++)
       for(int j = 0 ; j < C ; j++)
         dfs(i , j , 1 , -1);


       cout<<cad<<": "<<sol<<"\n";
    }

     return 0;
}
