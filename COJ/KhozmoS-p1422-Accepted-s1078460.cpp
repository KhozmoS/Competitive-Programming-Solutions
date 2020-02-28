#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e6 + 5;
const ll mod = 1000000009;

struct Node{

 ll sum;
 ll lazy;

  Node(){}
  Node(ll a , ll b):sum(a) , lazy(b){};

}ST[MAX * 4];

void build(int node , int x , int y)
{
    if(x == y)
    {
      ST[node] = Node(1 , 1);
      return;
    }
    int midle = (x + y) / 2;

    build(node * 2 , x , midle);
    build(node * 2 + 1 , midle + 1 , y);

    ST[node].sum = (ST[node * 2].sum + ST[node * 2 + 1].sum) % mod;
    ST[node].lazy = 1;

    return;
}

void propagate(int node , ll m)
{
   ST[node].lazy = (m * ST[node].lazy) % mod;
   ST[node].sum = (m * ST[node].sum) % mod;
}

void update(int node , int x , int y , ll m , int a , int b)
{
    if(x > b || y < a)
        return;

    if(x >= a && y <= b){
     ST[node].lazy = (m * ST[node].lazy) % mod;
     ST[node].sum = (ST[node].sum * m) % mod;
        return;
    }

    if(ST[node].lazy != 1)
    {
      propagate(node * 2 , ST[node].lazy);
      propagate(node * 2 + 1 , ST[node].lazy);
      ST[node].lazy = 1;
    }
    int midle = (x + y) / 2;

    update(node * 2 , x , midle , m , a , b);
    update(node * 2 + 1 , midle + 1 , y , m , a , b);

    ST[node].sum = (ST[node * 2].sum + ST[node * 2 + 1].sum) % mod;

    return;
}
ll query(int node , int x , int y , int a , int b)
{
  if(x > b || y < a)
    return 0;

  if(x >= a && y <= b)
  {
    return ST[node].sum;
  }
    if(ST[node].lazy != 1)
    {
      propagate(node * 2 , ST[node].lazy);
      propagate(node * 2 + 1 , ST[node].lazy);
      ST[node].lazy = 1;
    }
   int midle = (x + y) / 2;

   return (query(node * 2 , x , midle , a , b) + query(node * 2 + 1 , midle + 1 , y , a , b)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;

    while(cin>>n>>q){

    build(1 , 1 , n);

    //for(int i = 1 ; i <= 10 ; i++)
    //    cout<<ST[i].sum<<" ";

    while(q--)
    {
       int typ;
       cin>>typ;
       if(!typ){
         int a , b;
         ll k;
         cin>>a>>b>>k;
         update(1 , 1 , n , k , a , b);
       }
       else{
        int a , b;
        cin>>a>>b;
        cout<<query(1 , 1 , n , a , b)<<"\n";
       }
    }
    }
    return 0;
}
