#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define PB push_back
const int MAX = 1e5 + 5;

vector <int> adl[MAX];
typedef pair <int , int> nod;
int l[MAX] , r[MAX] , pos=-1 , id[MAX * 2];
int ST[MAX * 4];int col[MAX] , root;

void dfs(int node)
{
   id[++pos] = node;
   l[node] = pos;
   for(int i = 0 ; i < adl[node].size() ; i++)
       dfs(adl[node][i]);

   r[node] = pos;
}

void build(int node , int x , int y)
{
    if(x == y)
    {
       ST[node] = (col[id[x]] == 1);
       return;
    }

    int mt = (x+y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2+1 ,mt+1, y);

    ST[node] = ST[node * 2 + 1] + ST[node * 2];
}

bool lazy[MAX * 4];
void update(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        lazy[node] = !lazy[node];
        ST[node] = (y - x + 1) - ST[node];
        return;
    }
    int mt = (x + y) >>1;
    if(lazy[node])
    {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2+1] = !lazy[node * 2+1];

        ST[node * 2] = (mt - x + 1) - ST[node * 2];
        ST[node * 2+1] = (y - mt) - ST[node * 2+1];

        lazy[node] = false;
    }

    update(node * 2 , x , mt , a , b);
    update(node * 2 +1, mt+1 , y , a , b);

    ST[node] = ST[node * 2] + ST[node * 2 + 1];
}

int query(int node , int x ,int y , int a , int b)
{
    if(x > b || y < a) return 0;

    if(a <= x && y <= b)
        return ST[node];

    int mt = (x + y) >>1;
    if(lazy[node])
    {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2+1] = !lazy[node * 2+1];

        ST[node * 2] = (mt - x + 1) - ST[node * 2];
        ST[node * 2+1] = (y - mt) - ST[node * 2+1];

        lazy[node] = false;
    }

    return query(node * 2 , x , mt , a , b)+
    query(node * 2 +1, mt+1 , y , a , b);
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;


  for(int i = 1 ; i <= n ; i++)
  {
      int p;cin>>p>>col[i];

      adl[p].PB(i);
  }

  dfs(0);
  build(1 , 1 , n);

  int Q;cin>>Q;while(Q--)
  {
      int ty , X;
      cin>>ty>>X;

      if(!(ty-1))
           update(1 , 1 , n , l[X] , r[X]);
      else
           cout<<(query(1 , 1 , n , l[X] , r[X]) - query(1 , 1 , n , l[X] , l[X]))<<"\n";
  }
}
