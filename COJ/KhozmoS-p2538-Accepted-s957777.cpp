#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;
const int MAXN = 1111;

int D[MAXN][3];
int ar[MAXN];
int n;

int F(int pos , int mod)
{
    if(pos == n) return mod == 0;

    if(D[pos][mod] != -1)
    return D[pos][mod];

    return D[pos][mod] = (F(pos + 1 , mod) + F(pos + 1 , (mod + ar[pos]) % 3)) % MOD;
}


int main()
{
//    generar();
  ios_base::sync_with_stdio(0);cin.tie(0);
   memset(D , -1 , sizeof(D));
   cin>>n;

   for(int i = 0 ; i < n ; i++)
   cin>>ar[i];

   cout<<(MOD + F(0 , 0) - 1) % MOD<<"\n";

    return 0;
}
