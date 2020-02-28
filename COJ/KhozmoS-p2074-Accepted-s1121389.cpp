#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
const int MAX = 2 * 1e5 + 5;
typedef pair <int , int> par;
par ST[MAX * 4];
int cont;

map <int , int> kid;

void update(int node , int x , int y , int pos , int val)
{
    if(x > pos || y < pos)
        return;

    if(x == y)
    {
        ST[node].f = val;
        return;
    }
    int mit = (x + y) >> 1;

    update(node * 2 , x , mit , pos , val);
    update(node * 2 + 1, mit + 1 , y , pos , val);

     if(ST[node * 2].f > ST[node * 2 + 1].f)
       ST[node].s = ST[node * 2].s;

      else ST[node].s = ST[node * 2 + 1].s;

    ST[node].f = max(ST[node * 2].f , ST[node * 2 + 1].f);
}
par query(int node , int x , int y , int a , int b)
{
    if(x > b || y < a)
        return par(0 , 0);

    if(a <= x && y <= b)
    {
        return ST[node];
    }
    int mit = (x + y) >> 1;

    par izq = query(node * 2 , x , mit , a , b);
    par der = query(node * 2 + 1 , mit + 1 , y , a , b);

    if(izq.f > der.f)
        return izq;
    else
        return der;
}
int a[MAX];
int b[MAX];
int ver[MAX];
int c[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        if(!n) {cout<<"0\n";continue;}
        for(int i = 1 ; i <=  n ; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b + 1 , b + n + 1);
        int ind = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(kid.find(b[i]) == kid.end())
            {
                kid[b[i]] = ind;
                ind++;
            }
        }
        int ans = 1;
        int may = ind - 1;
        int pre[MAX];

        pre[n] = 1;
        for(int i = n - 1 ; i > 0 ; i--)
        {
            if(a[i] < a[i + 1])
                pre[i] = pre[i + 1] + 1;
            else
                pre[i] = 1;
        }
       // for(int i = 1 ; i <= n ;i++) cout<<pre[i]<<" ";
        //cout<<"\n";
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i] > a[i - 1])
                c[i] = c[i - 1] + 1;
            else
                c[i] = 1;

            int k = kid[a[i]];
            par x = query(1 , 1 , may , 1 , k - 1);

            if(query(1 , 1 , may , 1 , k).f < c[i])
            update(1 , 1 , may , k , c[i]);

            ans = max(ans , x.f + pre[i]);
        }

        int cant = 1;

        for(int i = 0 ; i < MAX ; i++) {a[i] = 0; b[i] = 0;}
        for(int i = 0 ; i < MAX * 4 ; i++)
            ST[i] = par(0 , 0);

        cout<<ans<<"\n";

        kid.clear();
    }

    return 0;
}
