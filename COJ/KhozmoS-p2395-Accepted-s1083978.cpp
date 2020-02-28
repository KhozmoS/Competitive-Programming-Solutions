#include <bits/stdc++.h>

using namespace std;
const int MAX = 50005;

int ST[MAX * 4] , st[MAX * 4];

void build(int node , int x , int y)
{
      if(x == y)
      {
          cin>>ST[node];
          st[node] = ST[node];
          return;
      }

      int mid = (x + y) / 2;
      build(node * 2 , x , mid);
      build(node * 2 + 1 , mid + 1 , y);

      ST[node] = max(ST[node * 2] , ST[node * 2 + 1]);
      st[node] = min(st[node * 2] , st[node * 2 + 1]);
}
int Query(int node , int x , int y , int a , int b)
{
    if(a > y || b < x)
        return -1;

    if(a <= x && b >= y)
        return ST[node];
    int mid = (x + y) / 2;

    return max(Query(node * 2 , x , mid , a , b) , Query(node * 2 + 1 , mid + 1 , y , a , b));
}
int query(int node , int x , int y , int a , int b)
{
    if(a > y || b < x)
        return 1e7;

    if(a <= x && b >= y)
        return st[node];
    int mid = (x + y) / 2;

    return min(query(node * 2 , x , mid , a , b) , query(node * 2 + 1 , mid + 1 , y , a , b));
}
int n , q;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>q;

   build(1 , 1 , n);

   while(q--)
   {
       int a , b;
       cin>>a>>b;
       cout<<Query(1 , 1 , n , a , b) - query(1 , 1 , n , a , b)<<"\n";
   }
    return 0;
}
