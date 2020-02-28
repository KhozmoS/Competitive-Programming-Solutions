#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define PB push_back
const int MAX = 5e5 + 5;

vector <int> adl[MAX];
typedef pair <int , int> nod;
int l[MAX] , r[MAX] , pos , id[MAX * 2];
int ST[MAX * 4];int col[MAX] , root;
bool mk[MAX] , lazy[MAX * 4];
void dfs(int node)
{
   l[node] = ++pos;
   for(int i = 0 ; i < adl[node].size() ; i++)
       dfs(adl[node][i]);

   r[node] = pos;
}
void build(int node , int x , int y)
{
    if(x == y)
    {
        ST[x] = 0;
        return;
    }

    int mt = (x + y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2 + 1,mt+1 , y);

    ST[node] = 0;
}

void update(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        lazy[node] = !lazy[node];
        ST[node] = (y - x + 1) - ST[node];
        return;
    }int mt = (x + y) >> 1;
    if(lazy[node])
    {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2+1] = !lazy[node * 2+1];
        ST[node * 2] = (mt - x + 1) - ST[node * 2];
        ST[node * 2+1] = (y - mt) - ST[node * 2+1];
        lazy[node] = !lazy[node];
    }

    update(node * 2 , x , mt , a , b);
    update(node * 2 +1,  mt+1 ,y , a , b);

    ST[node] = ST[node * 2] + ST[node * 2 + 1];
}


int query(int node  , int x , int y , int a , int b)
{
    if(x > b || y < a) return 0;

    if(a <= x && y <= b)
        return ST[node];
    int mt = (x + y) >> 1;
    if(lazy[node])
    {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2+1] = !lazy[node * 2+1];
        ST[node * 2] = (mt - x + 1) - ST[node * 2];
        ST[node * 2+1] = (y - mt) - ST[node * 2+1];
        lazy[node] = !lazy[node];
    }
    return query(node * 2 , x ,mt , a , b)+query(node * 2 + 1 , mt+1 , y , a , b);
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n , q;

  while(cin>>n>>q)
  {
      pos = 0;
      memset(mk , false , sizeof(mk));
      memset(lazy , false , sizeof(lazy));
      memset(ST , 0 , sizeof(ST));
      memset(l , 0 , sizeof(l));
      memset(r , 0 , sizeof(r));

      for(int i = 0 ; i < MAX ; i++) adl[i].clear();


      for(int i = 1 ; i < n ; i++)
      {
          int a,  b;cin>>a>>b;a++;b++;
          adl[a].PB(b);
          mk[b] = true;
      }
      for(int i = 1 ; i <= n ; i++)
      if(!mk[i]) {dfs(i);i = n+1;}

      build(1 , 1 , n);

      while(q--)
      {
          int ty , x;cin>>ty>>x;
          x++;
          if(!ty)
              update(1 , 1 , n , l[x] , r[x]);
          else
              cout<<query(1 , 1 , n , l[x] , r[x])<<"\n";
      }

  }
}
