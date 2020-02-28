#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111111;
const int MOD = 1000000007;

int abi[MAXN];
int ar[MAXN];

 void update(int pos , int val)
 {

     for(int i = pos ; i < MAXN ; i += (i & -i)){
      if(val < 0)
      {
        abi[i] =
        (abi[i] + val + MOD) % MOD;
      }
      else
      abi[i] = ((abi[i] % MOD) + (val % MOD)) % MOD;
     }
 }
 int sum(int x)
 {
     int suma = 0;
     for(int i = x ; i > 0 ; i -= (i & -i))
     suma = ((abi[i] % MOD) + (suma % MOD)) % MOD;

   return suma;
 }

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    int N;
    cin>>N;

    for(int i = 1 ; i < N ; i++)
    cin>>ar[i];
reverse(ar + 1 , ar + N);

    if(ar[1] == 0)
    {
        cout<<0<<"\n";
        return 0;
    }



    update(2 , 1);
    update(1 + ar[1] + 1, -1);


    for(int i = 2 ; i < N ; i++)
    {
      int suma = sum(i);
      update(i + 1, suma);
      update(i + ar[i] + 1, -suma);
    }

     cout<<sum(N)<<"\n";
    return 0;
}
