#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5+4;
int n , q;
#define f first
#define s second

typedef pair <int , int> ii;
struct nod{
    ii bl , br , bm;
    int best;
    nod()
    {
        bl.f = 0;
        br.f = 0;
        bm.f = 0;
        bl.s = 0;
        br.s = 0;
        bm.s = 0;
        best = 0;
    }
}ST[MAX*4];
int ar[MAX];
nod combine(nod a , nod b, int sza , int szb)
{
    nod res;
    res.bl = a.bl;
    res.br = b.br;
    if(sza == a.bl.f)
    {
        if(a.bl.s==b.bl.s)
            res.bl = ii(a.bl.f + b.bl.f , a.bl.s);
    }
    if(szb == b.br.f)
    {
        if(a.br.s==b.br.s)
            res.br = ii(a.br.f + b.br.f , a.br.s);
    }
    if(a.br.s==b.bl.s)
    {
        res.bm = ii(a.br.f + b.bl.f , a.br.s);
    }else{
        if(a.br.f == b.bl.f)
        {
            if(a.br.s > b.bl.s)
                res.bm = a.br;
            else
                res.bm = b.bl;
        }
        else if(a.br.f > b.bl.f)
        {
            res.bm = a.br;
        }
        else
        {
            res.bm = b.bl;
        }
    }

    if(a.bm.f == res.bm.f)
    {
        if(a.bm.s > res.bm.s)
            res.bm = a.bm;
    }
    else if(a.bm.f > res.bm.f)
    {
        res.bm = a.bm;
    }
    if(b.bm.f == res.bm.f)
    {
        if(b.bm.s > res.bm.s)
            res.bm = b.bm;
    }
    else if(b.bm.f > res.bm.f)
        res.bm = b.bm;
    res.best = max(a.best , b.best);
    return res;
}
void build(int node , int x , int y)
{
    if(x==y)
    {
        ST[node].bl = ii(1,ar[x]);
        ST[node].br = ii(1,ar[x]);
        ST[node].bm = ii(1,ar[x]);
        ST[node].best = ar[x];
        return;
    }
    int mt = (x+y)>>1;
    build(node*2 , x , mt);
    build(node*2+1 , mt+1 , y);
    ST[node] = combine(ST[node*2] , ST[node*2+1] , mt-x+1 , y-mt);
}
int query1(int node , int x , int y , int a , int b)
{
    if(y < a || x > b)
        return 0;
    if(a <= x && b >= y){
        //cout<<x<<" "<<y<<"wa\n";
        return ST[node].best;
    }

    int mt = (x+y)>>1;
    return max(query1(node*2 , x , mt , a , b) , query1(node*2+1, mt+1 , y , a , b));
}
nod query2(int node , int x , int y , int a , int b)
{
    if(y < a || x > b)
        return nod();
    if(a <= x && b >= y){
       // cout<<x<<" "<<y<<" wa\n";
        //cout<<ST[node].bm.f<<" "<<ST[node].bm.s<<"\n";
        return ST[node];
    }
    int mt = (x+y)>>1;
    //cout<<mt<<" "<<x<<" "<<y<<"\n";
    return combine(query2(node*2 , x , mt , a , b) , query2(node*2+1 , mt+1 , y , a , b) , mt-x+1 , y-mt);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i = 1 ; i <= n ; i++) cin>>ar[i];

    build(1 , 1 , n);
    //cout<<ST[1].bm.f<<" "<<ST[1].bm.s<<"\n";
    cin>>q;
    while(q--)
    {
        int t , a , b;
        cin>>t>>a>>b;
        if(t==1){
//            cout<<a<<" "<<b<<"\n";
            cout<<query1(1,1,n,a,b)<<"\n";
        }
        else{
            nod ans = query2(1, 1 , n , a , b);
            ii Ans = max(ans.bl , max(ans.br , ans.bm));
            cout<<Ans.f<<" "<<Ans.s<<"\n";
        }
    }
}
