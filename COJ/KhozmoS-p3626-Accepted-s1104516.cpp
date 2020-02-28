#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int ST[MAX * 4][11] , n , q  , prop[MAX * 4][11];
int num[11];
string cad;
bool lazy[MAX * 4];
void build(int node , int x , int y)
{
    if(x == y)
    {
        cin>>cad;
        for(int i = 0 ; i < cad.size() ; i++)
            ST[node][cad[i] - '0']++;

        return;
    }
    int mit = (x + y) >> 1;
    build(node * 2 , x , mit);
    build(node * 2 + 1 , mit + 1 , y);

    for(int i = 0 ; i < 10 ; i++)
        ST[node][i] = ST[node * 2][i] + ST[node * 2 + 1][i];
}
void propagate(int node , int x , int y)
{
    int mit = (x + y) >> 1;
    for(int i = 0 ; i < 10 ; i++)
    {
        ST[node * 2][i] = (prop[node][i] * (mit - x + 1));
        ST[node * 2 + 1][i] = (prop[node][i] * (y - mit));
        prop[node * 2][i] = prop[node][i];
        prop[node * 2 + 1][i] = prop[node][i];
    }
    lazy[node * 2] = true;
    lazy[node * 2 + 1] = true;

}
void update(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
      lazy[node] = true;
      for(int i = 0 ; i < 10 ; i++){
        ST[node][i] = (num[i] * (y - x + 1));
        prop[node][i] = num[i];
      }
      return;
    }
    if(lazy[node])
    {
        propagate(node , x , y);
        lazy[node] = false;
    }
    int mit = (x + y) >> 1;
    update(node * 2 , x , mit , a , b);
    update(node * 2 + 1, mit + 1 , y , a , b);

    for(int i = 0 ; i < 10 ; i++)
      ST[node][i] = ST[node * 2][i] + ST[node * 2 + 1][i];
}
void query(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
      for(int i = 0 ; i < 10 ; i++)
        num[i] += ST[node][i];

      return;
    }
    if(lazy[node])
    {
        propagate(node , x , y);
        lazy[node] = false;
    }
    int mit = (x + y) >> 1;
    query(node * 2 , x , mit , a , b);
    query(node * 2 + 1, mit + 1 , y , a , b);

}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    build(1 , 1 , n);
    while(q--)
    {
        int typ , a , b;
        cin>>typ>>a>>b;
        if(typ)
        {
            cin>>cad;
            for(int i = 0 ; i < cad.size() ; i++)
                num[cad[i] - '0']++;
            update(1 , 1 , n , a , b);
            for(int i = 0 ; i < 10 ; i++) num[i] = 0;

            continue;
        }
        query(1 , 1 , n , a , b);
        int may = -1;
        int ans = -1;
        for(int i = 0 ; i < 10 ; i++)
         {
             if(may < num[i])
             {
                 may = num[i];
                 ans = i;
             }
             num[i] = 0;
         }

         cout<<ans<<"\n";
    }
    return 0;
}
