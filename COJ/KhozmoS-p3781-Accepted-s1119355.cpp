#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e5 * 5 + 7;
const ll mod = 1e9 + 7;

ll ST[MAX * 5] , b;

ll exp(ll a , ll b)
{
    ll ans = 1;

    while(b)
    {
        if(b & 1)
          ans = (ans * a) % mod;
       b >>= 1;
       a = (a * a) % mod;
    }

    return ans;
}

void build(int node , int x , int y){

  if(x == y)
  {
      ll e;
      cin>>e;
      ST[node] = exp(b , e);
      return;
  }

  int mit = (x + y) >> 1;

  build(node * 2, x , mit);
  build(node * 2 + 1 , mit + 1 , y);

  ST[node] = (ST[node * 2] + ST[node * 2 + 1]) % mod;
  ST[node] += (ST[node * 2] * ST[node * 2 + 1]) % mod;
  ST[node] %= mod;
}

ll query(int node , int x , int y , int a , int b)
{
    if(x > b || y < a) return 0;

    if(a <= x && b >= y)
        return ST[node];

    int mit = (x + y) >> 1;

    ll sa = query(node * 2 , x , mit , a , b);
    ll sb = query(node * 2 + 1, mit + 1 , y , a , b);

    ll res = (sa + sb) % mod;
    res += (sa * sb) % mod;
    res %= mod;
    return res;
}

int main()
{
   // cout<<exp(2 , 5);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n>>b){
    build(1 , 1 , n);
    int q; cin>>q;

    while(q--)
    {
        int a , b;
        cin>>a>>b;
        cout<<query(1 , 1 , n , a , b)<<"\n";
    }
    }
    return 0;
}
/*
4 2
3 5 2 7
5
1 1
1 2
2 3
1 4
3 3


*/
