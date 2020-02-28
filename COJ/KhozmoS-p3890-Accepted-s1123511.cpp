#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;

typedef pair <int , int> par;

const ll MAX = 1e8 + 5;
const ll mod = 1e6 + 5;
ll ar[mod * 10];

int bin(int in , int fn , ll x)
{
    int mt = (in + fn) >> 1;

    if(fn - in < 3)
    {
        for(int i = in ; i <= fn ; i++)
            if(ar[i] > x)
              return i - 1;

    }
    if(ar[mt] > x) return bin(in , mt , x);

    return bin(mt , fn , x);
}
ll ans[mod * 10];
int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);
   ar[1] = 1;
   ans[1] = 1;
   int ind  = 2;
   ll co = (MAX * MAX * 100);
   for(ll i = 1 ; i < MAX ; i++)
   {
       ar[ind] = ar[ind - 1] + (4 * (ind - 1));
       ans[ind] = ar[ind];
       ans[ind] += ans[ind - 1];

       ind++;

       if(ans[ind - 1] > co){
          break;
       }
   }
   //cout<<ind<<"\n";
   //for(int i = 1 ; i < 10 ; i++){cout<<ans[i]<<" "<<ar[i]<<"\n";}
   ll x; cin>>x;
   for(int i = 0 ; i < ind ; i++)
    if(ans[i] > x)
 {
     cout<<i - 1<<"\n";
     return 0;
 }
}
