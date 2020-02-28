#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

vector <int> ST[MAX*5];
int Q[MAX * 5];int pos , k;
int ar[MAX];

void build(int node , int x , int y)
{
   ST[node].clear();
   if(x == y)
   {
       ST[node].push_back(ar[x]);
       return;
   }

   int mt = (x + y)>>1;
   build(node * 2 , x , mt);
   build(node * 2+1 , mt+1 , y);

   for(int i = 0 ; i < ST[node * 2].size() ; i++)
       ST[node].push_back(ST[node*2][i]);

   for(int i = 0 ; i < ST[node * 2+1].size() ; i++)
       ST[node].push_back(ST[node*2+1][i]);

       sort(ST[node].begin() , ST[node].end());
}

void query(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return;

    if(a <= x && y <= b)
    {
        Q[pos++] = node;
        return;
    }
    int mt = (x + y)>>1;
    query(node * 2 , x , mt , a , b);
    query(node * 2+1 , mt+1 , y, a , b);
}
bool ok(int x)
{
    int ind = 0;
    for(int i = 0 ; i < pos ; i++)
        ind += (lower_bound(ST[Q[i]].begin() , ST[Q[i]].end() , x) - ST[Q[i]].begin());
   // if(x <= 100)
    //cout<<ind<<" "<<x<<"\n";
    return (ind+1 > k);
}
int solve()
{
    int in = 0 , fn = 1e9 + 5;
    while(in + 1 < fn)
    {
       int mt = (in+fn)>>1;

       if(ok(mt))
            fn = mt;
       else
            in = mt;
    }

    return fn-1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;

    while(cin>>n>>q)
    {
        for(int i = 1 ; i <= n ; i++) cin>>ar[i];
        build(1 , 1 , n);
        while(q--)
        {
            pos = 0;
            int a , b;cin>>a>>b>>k;
            if(a > b) swap(a , b);

            query(1 , 1 , n , a , b);
            cout<<solve()<<"\n";
        }
    }
}
