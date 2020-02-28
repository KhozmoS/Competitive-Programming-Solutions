#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 5555555;

typedef long long ll;


ll ar[MAXN];

int bins(ll n)
{
    int ini = 0;
    int fin = MAXN;
   while(fin - ini > 3)
   {
       int mit = (fin + ini) / 2;

       if(n > ar[mit])
       ini = mit;
       else
       fin = mit;
   }

    for(int i = fin ; i >= ini ; i--)
    if(ar[i] <= n)
    return i;

}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);//
     ar[0] = 0;
     for(ll i = 1 ; i < MAXN ; i++){
     ar[i] = ar[i - 1] + i;
    // cout<<ar[i]<<" ";
     }

    ll a , b;
    while(cin>>a>>b && (a && b))
    cout<<bins(b) - bins(a - 1)<<"\n";

    return 0;
}
