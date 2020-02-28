#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double


typedef long long ll;
typedef pair <ll ,ll> par;
typedef pair <par , int> trio;

const int MAX = 1e5+5;

ll ST[MAX*4];
ll lazy1[MAX*4];
par lazy2[MAX*4];

ll formule(ll in , ll sz , ll jmp)
{
    ll fn = ((sz-1)*jmp)+in;

    return ((fn+in)*sz)/2ll;
}
void build(int node , int x , int y)
{
    if(x==y)
    {
        cin>>ST[node];
        return;
    }

    int mt = (x+y)>>1;

    build(node*2 , x , mt);
    build(node*2+1 , mt+1 , y);
    ST[node] = ST[node*2]+ST[node*2+1];
}
void propagate(int node , int x , int y , int mt)
{
     if(lazy1[node] != -1)
        {
        lazy1[node*2] = lazy1[node];
        lazy1[node*2+1] = lazy1[node];
        ST[node*2] = (mt-x+1)*lazy1[node];
        ST[node*2+1] = (y-mt)*lazy1[node];
        lazy2[node*2] = par(0 , 0);
        lazy2[node*2+1] = par(0 , 0);

        lazy1[node] = -1;
        }
    
    if(lazy2[node].f){
        lazy2[node*2].f += lazy2[node].f;
        lazy2[node*2].s += lazy2[node].s;
        ST[node*2] += formule(lazy2[node].f , mt-x+1 , lazy2[node].s);

        lazy2[node*2+1].f += (lazy2[node].f + (1ll*(mt-x+1)*lazy2[node].s));
        lazy2[node*2+1].s += lazy2[node].s;
        ST[node*2+1] += formule((lazy2[node].f + (1ll*(mt-x+1)*lazy2[node].s)) , y-mt , lazy2[node].s);

        lazy2[node].f = 0;
        lazy2[node].s = 0;
    }
}
void update1(int node , int x, int y , int a ,int b , int v)
{
    if(x>b || y < a) return;

    if(x >= a && y <= b)
    {
        lazy2[node] = par(0 , 0);
        lazy1[node] = v;
        ST[node] = 1ll*(y-x+1)*v;
        return;
    }

    int mt = (x+y)>>1;
    propagate(node , x , y , mt);

    update1(node*2 , x , mt , a , b , v);
    update1(node*2+1 , mt+1 , y , a , b , v);

    ST[node] = ST[node*2]+ST[node*2+1];
}
void update2(int node ,int x, int y , int a , int b)
{
    if(x>b || y < a) return;

    if(x >= a && y <= b)
    {
        lazy2[node].f += x-a+1;
        lazy2[node].s++;
       // cout<<x<<" "<<a<<"\n";
        ST[node] += formule(x-a+1 , y-x+1 , 1);
        return;
    }

    int mt = (x+y)>>1;
    //propagate for lazy1
    propagate(node , x , y , mt);

    update2(node*2 , x , mt , a , b);
    update2(node*2+1 , mt+1 , y , a , b);

    ST[node] = ST[node*2]+ST[node*2+1];
}

ll query(int node , int x , int y , int a , int b)
{
    if(x>b || y < a) return 0;

    if(x >= a && y <= b)
        return ST[node];
    int mt = (x+y)>>1;

    propagate(node , x , y , mt);

    return query(node*2 , x , mt , a , b)+query(node*2+1 , mt+1 , y , a , b);
}

int main()
{
    memset(lazy1 , -1 , sizeof(lazy1));
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;
    cin>>n>>q;
    build(1 , 1 , n);
    while(q--)
    {
        int typ , a , b , x;

        cin>>typ>>a>>b;
        if(typ==1)
        {
            cin>>x;
            update1(1 , 1,n , a , b , x);
            continue;
        }
        if(typ==2)
        {
            update2(1 , 1 , n , a , b);
            continue;
        }

        cout<<query(1 , 1 , n , a , b)<<"\n";
    }
}
/*
8 4
0 0 0 0 0 0 0 0
2 5 8
3 5 6
1 5 8 100
3 6 6
*/
