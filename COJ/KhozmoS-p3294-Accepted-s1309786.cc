#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 10000019;
const int MAX = 2*1e6+5;
ii ST[MAX*4];
bool mk[MAX];
int ar[100006];

void criba()
{
    mk[0] = 1;
    mk[1] = 1;

    for(int i = 2 ; i * i < MAX ; i++)
    {
        if(!mk[i])
            for(int j = i*i ; j < MAX ; j += i)
                mk[j] = true;
    }
}

void build(int node , int x , int y)
{
    if(x==y)
    {
        ST[node].f = !mk[ar[x]];
        ST[node].s = (mk[ar[x]] ? ar[x] : -1);
        return;
    }
    int mt = (x+y)>>1;
    build(node*2,x,mt);
    build(node*2+1,mt+1,y);
    ST[node].f = ST[node*2].f+ST[node*2+1].f;
    ST[node].s = max(ST[node*2].s,ST[node*2+1].s);
}
void update(int node , int x , int y , int p , int v)
{
    if(x > p || y < p) return;
    if(x==y)
    {
        ST[node].f = !mk[v];
        ST[node].s = (mk[v] ? v : -1);
        return;
    }
    int mt = (x+y)>>1;
    update(node*2,x,mt,p,v);
    update(node*2+1,mt+1,y,p,v);
    ST[node].f = ST[node*2].f+ST[node*2+1].f;
    ST[node].s = max(ST[node*2].s,ST[node*2+1].s);
}
ii query(int node ,int x , int y , int a , int b)
{
   if(x > b || y < a) return ii(0,-1);
    if(x>=a && y <= b)
    {
        return ST[node];
    }
    int mt = (x+y)>>1;
    ii q1 = query(node*2,x,mt,a,b);
    ii q2 = query(node*2+1,mt+1,y,a,b);
    ii res;
    res.f = q1.f+q2.f;
    res.s = max(q1.s,q2.s);
    return res;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   criba();
//   for(int i = 1 ; i <= 20 ; i++)
//        cout<<i<<" "<<mk[i]<<"\n";
   int n , q;cin>>n>>q;
   for(int i = 1 ; i <= n ;i++) cin>>ar[i];
   build(1 , 1 , n);
   while(q--)
   {
       int op , a , b;
       cin>>op>>a>>b;
       if(op==1)
       {
           update(1 , 1 , n , a , b);
       }
       else if(op==2)
       {
           ii ans = query(1 , 1 , n , a , b);
           cout<<ans.f<<"\n";
       }
       else if(op==3){
           ii ans = query(1 , 1 , n , a , b);
           if(ans.s==-1)
                cout<<"NO ANSWER"<<"\n";
           else
                cout<<ans.s<<"\n";
       }
   }
}
