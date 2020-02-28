#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair <int , int > par;
const int MAXN = 105;
int mx[] = {-1 , 0 , 1 , 0};
int my[] = { 0 , 1 , 0 , -1};
queue<par>cola;
bool mk[MAXN][MAXN];
char camp[MAXN][MAXN];
bool vale(par n)
{
    if(n.first >= 0 && n.first < MAXN && n.second >= 0 && n.second < MAXN && camp[n.first][n.second] == 'H' && !mk[n.first][n.second])
    return true;
    return false;
}
void bfs(int x ,int  y)
{
    par ini;
    ini.first = x; ini.second = y;
    cola.push(ini);
    while(!cola.empty())
    {
     par n = cola.front(); cola.pop();
     camp[n.first][n.second] = 'X';
     for(int i = 0 ; i < 4 ; i++)
     {
         par nn;
         nn.first = n.first + mx[i];
         nn.second = n.second + my[i];
         if(vale(nn))
         {
            cola.push(nn);
            mk[nn.first][nn.second] = true;
         }
     }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < MAXN ; i++)
    for(int j = 0 ; j < MAXN ; j++)
    camp[i][j] = 'H';
    int t;
    cin>>t;
    while(t--)
    {
        int x , y;
        cin>>x>>y;
        camp[y][x] = 'M';
    }
    bfs(0 , 0);
   /* for(int i = 1 ; i <= 10 ; i++){
    for(int j = 1 ; j <= 10 ;j++)
    cout<<camp[i][j]<<" ";
    cout<<"\n";
    }*/int sol = 0;
    for(int i = 1 ; i <= 100 ; i++){
    for(int j = 1 ; j <= 100 ; j++){
    if(camp[i][j] == 'M')
    {
      par n;
      n.first = i; n.second = j;
      for(int i = 0 ; i < 4 ; i++)
      {
          par nn;
          nn.first = n.first + mx[i];
          nn.second = n.second + my[i];
          if(camp[nn.first][nn.second] == 'X')
          sol++;
      }
    }
    }
    }
    cout<<sol<<"\n";
    return 0;
}
