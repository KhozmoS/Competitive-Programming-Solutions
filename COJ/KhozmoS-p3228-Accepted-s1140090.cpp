#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
const int MAX = 1e5 + 5;
int ar[MAX] , n , a , b , q;
typedef pair <int , int> nod;
nod ST[MAX * 4];
char typ;

void build(int node , int x , int y)
{
    if(x == y)
    {
        ST[node] = nod(x , x);
        return;
    }

    int mt = (x + y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2 + 1 , mt + 1 , y);

    ST[node].f = (ar[ST[node * 2].f] < ar[ST[node * 2 + 1].f] ? ST[node * 2].f : ST[node * 2 + 1].f);
    ST[node].s = (ar[ST[node * 2].s] > ar[ST[node * 2 + 1].s] ? ST[node * 2].s : ST[node * 2 + 1].s);
}

void update(int node , int x , int y , int v)
{
    if(a > y || a < x) return;

    if(x == y)
    {
        ar[x] = v;
        return;
    }
    int mt = (x + y) >> 1;

    update(node * 2 , x , mt , v);
    update(node * 2 + 1 , mt + 1 , y , v);

    ST[node].f = (ar[ST[node * 2].f] < ar[ST[node * 2 + 1].f] ? ST[node * 2].f : ST[node * 2 + 1].f);
    ST[node].s = (ar[ST[node * 2].s] > ar[ST[node * 2 + 1].s] ? ST[node * 2].s : ST[node * 2 + 1].s);

}
int query(int node , int x , int y , int v)
{
    if(a > y || b < x) return 0;

    if(v < ar[ST[node].f]) return 0;

    if(x >= a && y <= b && v >= ar[ST[node].s])
        return y - x + 1;
    int mt = (x + y) >> 1;
    return  query(node * 2 , x , mt , v) +
    query(node * 2 + 1 , mt + 1 , y , v);

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;

    for(int i = 1 ; i <= n ; i++) cin>>ar[i];
    build(1 , 1 , n);

    while(q--)
    {
        cin>>typ>>a>>b;

        if(!(typ - 'Q'))
          {
              int x;
              cin>>x;
              cout<<query(1 , 1 , n , x)<<"\n";continue;
          }

        update(1 , 1 , n , b);

    }


}
