#include <bits/stdc++.h>

using namespace std;

string cad;
const int MAX = 1e5+6;
struct node{
    int a, b;
}ST[MAX*4];



node combine(node left , node right)
{
    int eq = min(left.a , right.b);

    node res;
    res.a = (left.a - eq) + right.a;
    res.b = (right.b - eq) + left.b;

    return res;
}
void build(int node , int x , int y)
{
    if(x==y)
    {
        ST[node].a = (cad[x-1] == '(');
        ST[node].b = (cad[x-1] == ')');
        return;
    }

    int mt = (x+y)>>1;
    build(node*2 , x , mt);
    build(node*2+1 , mt+1 , y);

    ST[node] = combine(ST[node*2] , ST[node*2+1]);
}

void update(int node , int x ,int y , int a, int b)
{
    if(x > b || y < a) return;

    if(x >= a && y <= b)
    {
        ST[node].a = !ST[node].a;
        ST[node].b = !ST[node].b;
        return;
    }

    int mt = (x+y)>>1;
    update(node*2 , x , mt , a , b);
    update(node*2+1 , mt+1 , y , a , b);

    ST[node] = combine(ST[node*2] , ST[node*2+1]);
}

node query(int node , int x , int y , int a, int b)
{
    if(x > b || y < a) return ST[0];

    if(x >= a && y <= b)
        return ST[node];

    int mt  = (x+y)>>1;

    return combine(query(node*2 , x , mt , a , b) , query(node*2+1 , mt+1, y , a , b));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ST[0].a = 0;
    ST[0].b = 0;
    int q , oc , cc , k;
    cin>>cad;
    int n  = cad.size();
    build(1 , 1 , n);
    cin>>q>>oc>>cc>>k;

    while(q--){
        int typ , a , b;
        cin>>typ;
        cin>>a;
        if(typ==1)
        {
            update(1 , 1 , n , a , a);
            continue;
        }
        cin>>b;
        node res = query(1 , 1 , n , a , b);
        if((res.a&1) != (res.b&1))
        {
            cout<<"Impossible\n";
            continue;
        }
        int l = (res.a/2 + (res.a&1));
        int r = (res.b/2 + (res.b&1));
        if(l+r>k)
        {
            cout<<"Impossible\n";
            continue;
        }
        cout<<(l*oc)+(r*cc)<<"\n";
    }


}
