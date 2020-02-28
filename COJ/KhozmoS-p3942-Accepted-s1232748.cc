#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

map <int , int> id;
typedef pair <int , int> pa;
typedef pair <pa , int> p;
vector <p> Q;
vector <int> v;

int ST[5000005];


void update(int node , int x , int y , int a , int b , int val)
{
    if(x > b || y < a) return;


    if(x >= a && y <= b)
    {
        ST[node] = val;
        return;
    }

    int mt = (x+y)>>1;

    update(node*2 , x , mt , a , b , val);
    update(node*2+1 , mt+1 , y , a , b , val);

    ST[node] = min(ST[node*2] , ST[node*2+1]);
}
int num;
int query(int node , int x , int y , int a , int b , int val)
{
    if(x > b || y < a) return 0;

    if(ST[node] > val) return 0;

    if(x >= a && y <= b)
    {
        if(x == y) return x;

        if(ST[node*2] <= val) return query(node*2 , x , (x+y)>>1 , a , b , val);
        return query(node*2+1 , ((x+y)>>1) + 1 , y , a , b , val);
    }
    int mt = (x+y)>>1;
    int v1 = query(node*2 , x , mt , a , b , val);
    int v2 = query(node*2+1 , mt+1 , y , a , b , val);
    if(!v1 && !v2) return 0;
    if(!v1 && v2) return v2;
    if(!v2 && v1) return v1;
    return min(v1 , v2);
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i = 0 ; i < 5000005 ; i++)
   {
       ST[i] = INT_MAX;
   }

   int n , q;
   cin>>n>>q;
   while(q--)
   {
       int a, b;
       char c;
       cin>>c;
       if(c == 'M')
       {
           cin>>a>>b;
           Q.push_back(p(pa(a , b) , 0));
       }
       else{
           cin>>a>>b;
           Q.push_back(p(pa(a , b) , 1));
       }
   }

   for(int i = 0 ; i < Q.size() ; i++)
   {
       if(!Q[i].s)
           update(1 , 1 , n , Q[i].f.s , Q[i].f.s , Q[i].f.f);

       else{
           int ans = 0;
           ans = query(1 , 1 , n , Q[i].f.s , n , Q[i].f.f);
           if(!ans) cout<<"-1\n";
           else cout<<ans<<"\n";
       }
   }
}
/*
3 4
M 10 3
M 5 1
D 20 2
D 5 2
*/
