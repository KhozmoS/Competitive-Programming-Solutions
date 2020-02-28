#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int n , m;
struct nod{

  int ltr , rtl , best , med , slr , srl , smed;
  nod(int full , int st)
  {
      ltr = full;
      rtl = full;
      best = full;
      med = full;
      slr = st;
      srl = st;
      smed = st;
  }
  nod(){
    ltr = 0; best = 0;
    rtl = 0; med = 0;
    srl = 0;slr = 0; smed = 0;
  }

}ST[MAX * 10];

nod combination(nod a , nod b , int inb)
{
    nod res;
    if(a.ltr){
        res.ltr = a.ltr + (a.srl == a.slr ? b.ltr : 0);
        res.slr = a.slr;
    }
    else{
        res.ltr = 0;
        res.slr = 0;
    }
    if(b.rtl)
    {
       res.rtl = b.rtl + (b.srl == inb ? (a.rtl ? a.rtl : 0) : 0);
       res.srl = (b.srl == inb ? (a.rtl ? a.srl : b.srl) : b.srl);
    }
    else{
       res.rtl = 0;
       res.srl = 0;
    }
    if(a.rtl && b.ltr)
    {
       res.smed = a.srl;
       res.med = a.rtl + b.ltr;
    }
    else{
       res.med = 0;
       res.smed = 0;
    }

    res.best = max(res.ltr , max(res.rtl , res.med));
    res.best = max(res.best , max(a.best , b.best));

    return res;
}

void build(int node , int x ,int y)
{
    if(x == y)
    {
        ST[node].ltr = 1;
        ST[node].rtl = 1;
        ST[node].best = 1;
        ST[node].med = 1;
        ST[node].srl = x;
        ST[node].slr = x;
        ST[node].smed = x;
        return;
    }

    int mt = (x + y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2 + 1 , mt+1 , y);

    ST[node] = combination(ST[node * 2] , ST[node * 2 + 1] , mt + 1);
}
int lazy[MAX * 10];

void update(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        lazy[node] = 2;

        ST[node] = nod(y - x + 1 , x);

        return;
    }

    int mt = (x + y) >> 1;

    if(lazy[node] == 2)
    {
        ST[node * 2] = nod(mt - x + 1 , x);
        ST[node * 2 + 1] = nod(y - mt , mt+1);
        lazy[node * 2] = 2;
        lazy[node * 2 + 1] = 2;
        lazy[node] = 0;
    }
    if(lazy[node] == 1)
    {
        ST[node * 2] = nod();
        ST[node * 2 + 1] = nod();
        lazy[node * 2] = 1;
        lazy[node * 2 + 1] = 1;
        lazy[node] = 0;
    }

    update(node * 2 , x , mt , a , b);
    update(node * 2 + 1, mt+1 , y , a , b);

    ST[node] = combination(ST[node * 2] , ST[node * 2 + 1] , mt + 1);
}
void update1(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        lazy[node] = 1;
        ST[node] = nod();
        return;
    }

    int mt = (x + y) >> 1;

    if(lazy[node] == 2)
    {
        ST[node * 2] = nod(mt - x + 1 , x);
        ST[node * 2 + 1] = nod(y - mt , mt+1);
        lazy[node * 2] = 2;
        lazy[node * 2 + 1] = 2;
        lazy[node] = 0;
    }
    if(lazy[node] == 1)
    {
        ST[node * 2] = nod();
        ST[node * 2 + 1] = nod();
        lazy[node * 2] = 1;
        lazy[node * 2 + 1] = 1;
        lazy[node] = 0;
    }

    update1(node * 2 , x , mt , a , b);
    update1(node * 2 + 1, mt+1 , y , a , b);

    ST[node] = combination(ST[node * 2] , ST[node * 2 + 1] , mt + 1);
}
int query(int node ,int x ,int y , int value)
{
    if(ST[node].best < value)
        return 0;

    int mt = (x + y) >> 1;

    if(lazy[node] == 2)
    {
        ST[node * 2] = nod(mt - x + 1 , x);
        ST[node * 2 + 1] = nod(y - mt , mt+1);
        lazy[node * 2] = 2;
        lazy[node * 2 + 1] = 2;
        lazy[node] = 0;
    }
    if(lazy[node] == 1)
    {
        ST[node * 2] = nod();
        ST[node * 2 + 1] = nod();
        lazy[node * 2] = 1;
        lazy[node * 2 + 1] = 1;
        lazy[node] = 0;
    }
    if(ST[node].ltr >= value)
        return ST[node].slr;

    if(ST[node * 2].best < value && ST[node].med >= value)
            return ST[node].smed;
    if(ST[node * 2].best < value && ST[node * 2 + 1].best < value && ST[node].rtl >= value)
        return ST[node].srl;

    if(ST[node * 2].best >= value)
        return query(node * 2 , x , mt , value);

    return query(node * 2 + 1, mt+1 , y , value);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    build(1 , 1 , n);

    while(m--)
    {
        int ty , a , b;
        cin>>ty>>a;
        if(ty - 1)
        {
            cin>>b;
            if(a >= 1 && a + b - 1 <= n);
            update(1 , 1 , n , a , a + b - 1);
            continue;
        }

        int ans = query(1 , 1 , n , a);

        cout<<ans<<"\n";

        if(ans >= 1 && ans + a - 1 <= n && ans)
        update1(1 , 1 , n , ans , ans + a - 1);
    }
}
/*
10 6
1 3
1 3
1 3
1 3
2 5 5
1 6
*/
