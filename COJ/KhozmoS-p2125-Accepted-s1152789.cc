#include <bits/stdc++.h>

using namespace std;



const int MAX = 1e5 + 5;
int n , q;

struct nod{
  int cer , neg , pos;
  nod(int a , int b , int c){
    cer = a;neg = b; pos = c;
  }
  nod(){};
}ST[MAX * 5];

void build(int node , int x , int y)
{
    if(x == y)
    {
        int a;cin>>a;
        if(a == 0)
            ST[node] = nod(1 , 0 , 0);
        if(a < 0)
            ST[node] = nod(0 , 1 , 0);
        if(a > 0)
            ST[node] = nod(0 , 0 , 1);
        return;
    }
    int mt = (x + y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2 + 1, mt +1 , y);
    ST[node].cer = ST[node * 2].cer + ST[node * 2 + 1].cer;
    ST[node].pos = ST[node * 2].pos + ST[node * 2 + 1].pos;
    ST[node].neg = ST[node * 2].neg + ST[node * 2 + 1].neg;
}

void update(int node , int x ,int y , int a , int v)
{
    if(a > y || a < x) return;

    if(x == y)
    {

        if(v == 0)
            ST[node] = nod(1 , 0 , 0);
        if(v < 0)
            ST[node] = nod(0 , 1 , 0);
        if(v > 0)
            ST[node] = nod(0 , 0 , 1);
        return;
    }

    int mt = (x + y) >> 1;

    update(node * 2 , x , mt , a , v);
    update(node * 2 + 1, mt +1 , y , a , v);
    ST[node].cer = ST[node * 2].cer + ST[node * 2 + 1].cer;
    ST[node].pos = ST[node * 2].pos + ST[node * 2 + 1].pos;
    ST[node].neg = ST[node * 2].neg + ST[node * 2 + 1].neg;
}
nod query(int node , int x , int y , int a , int b)
{
    if(a > y || b < x) return nod(0 , 0, 0);

    if(a <= x && b >= y)
        return ST[node];

    int mt = (x + y) >> 1;

    nod X = query(node * 2 , x , mt , a , b);
    nod Y = query(node * 2 + 1, mt +1 , y , a , b);
    nod Z;
    Z.cer = X.cer + Y.cer;
    Z.pos = X.pos + Y.pos;
    Z.neg = X.neg + Y.neg;

    return Z;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    while(cin>>n>>q)
    {
        build(1 , 1 , n);
        char ty; int a ; int b;

        while(q--){
        cin>>ty>>a>>b;
        if(!(ty - 'C'))
        {
            update(1 , 1 , n , a , b);
            continue;
        }

        nod ans = query(1 , 1 , n , a , b);

        if(ans.cer) cout<<'0';
        else if(ans.neg&1) cout<<'-';
        else cout<<'+';
        }
        cout<<"\n";
    }


}
