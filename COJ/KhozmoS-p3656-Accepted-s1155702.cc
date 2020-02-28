#include <bits/stdc++.h>


using namespace std;

const int MAX = (1e6 * 4) + 5;

int pos , n , q;
int ar[MAX] , le[MAX] , ri[MAX];
int id[MAX];
int sal[MAX];
bool mk[MAX];

vector<int> adl[MAX];

stack <int> pila;

void dfs(int node)
{

  pila.push(node);

  int ind = 0;
  while(!pila.empty())
  {
      bool flag = false;

      node = pila.top();

      if(!le[node])
      {
          le[node] = ++pos;
          id[pos] = node;
      }
      for(int i = 0 ; i < adl[node].size() ; i++)
      {
          int x = adl[node][i];
          if(mk[x]) continue;

          mk[x] = true;

          flag = true;
          pila.push(x);
          break;
      }

      if(!flag) {
        ri[node] = ++pos;
        id[pos] = node;
        pila.pop();
      }
  }

}

struct nod{

  int mi , ma;
  nod(){mi = 0; ma = 0;}

}ST[MAX * 5];


void build(int node , int x , int y)
{
    if(x == y)
    {
       ST[node].mi = sal[id[x]];
       ST[node].ma = sal[id[x]];

       return;
    }

    int mt = (x + y) >>1;

    build(node * 2 , x , mt);
    build(node * 2+1 , mt+1 ,y);

    ST[node].mi = min(ST[node * 2].mi, ST[node*2+1].mi);
    ST[node].ma = max(ST[node * 2].ma, ST[node*2+1].ma);
}
int lazy[MAX * 5];
void update(int node , int x , int y , int a , int b , int v)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        lazy[node] += v;
        ST[node].mi+=v;
        ST[node].ma+=v;
        return;
    }
    if(lazy[node])
    {
        ST[node*2].mi+=lazy[node];
        ST[node*2].ma+=lazy[node];
        ST[node*2+1].mi+=lazy[node];
        ST[node*2+1].ma+=lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2+1] += lazy[node];
        lazy[node] = 0;
    }

    int mt = (x + y) >> 1;

    update(node * 2 , x , mt , a , b , v);
    update(node * 2+1 , mt+1 ,y , a , b , v);

    ST[node].mi = min(ST[node * 2].mi, ST[node*2+1].mi);
    ST[node].ma = max(ST[node * 2].ma, ST[node*2+1].ma);

}

typedef pair <int , int> par;

par query(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return par(-1 , -1);

    if(a <= x && y <= b)
       return par(ST[node].mi , ST[node].ma);

     if(lazy[node])
    {
        ST[node*2].mi += lazy[node];
        ST[node*2].ma+=lazy[node];
        ST[node*2+1].mi+=lazy[node];
        ST[node*2+1].ma+=lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2+1] += lazy[node];
        lazy[node] = 0;
    }
    int mt = (x + y) >> 1;

    par q1 = query(node * 2 , x , mt , a , b);
    par q2 = query(node * 2+1 , mt+1 , y , a , b);
    if(q1.first == -1 &&  q2.first == -1) return par(1000000000 , 0);
    if(q1.first == -1) return q2;
    if(q2.first == -1) return q1;

    return par(min(q1.first , q2.first) , max(q1.second , q2.second));

}
void clean()
{
    for(int i = 0 ; i < MAX ; i++){
        adl[i].clear();
        le[i] = 0;
        ri[i] = 0;
        id[i] = 0;
        sal[i] = 0;
        mk[i] = false;
    }
    for(int i = 0 ; i < MAX * 5 ; i++){
        ST[i] = nod();
        lazy[i] = 0;
    }

    pos = 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    n = 0;
    while(t--)
    {
         
        clean();
        cin>>n;
        for(int i = 2 ; i <= n ; i++)
        {
            int a;cin>>a;

            adl[a].push_back(i);
        }
        for(int i = 1 ; i <= n ; i++) cin>>sal[i];
           
        dfs(1);
        build(1 , 1 , pos);

        cin>>q;
        while(q--)
        {
            char ty;cin>>ty;int a;cin>>a;

            if(!(ty-'Q'))
            {
                par ans = query(1 , 1 , pos , le[a] , ri[a]);


                cout<<abs(ans.first - ans.second)<<"\n";
                continue;
            }
            int b;cin>>b;
            update(1 , 1 , pos , le[a] , ri[a] , b);
        }

    }


}
