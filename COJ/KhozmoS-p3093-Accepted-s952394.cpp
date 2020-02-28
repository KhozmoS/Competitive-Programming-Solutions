#include <bits/stdc++.h>

using namespace std;

const int MOD = 26;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  int mult = 1;
  string cad;
  cin>>cad;

   for(int i = 0 ; i < cad.size() ; i++)
   {
       mult = (((cad[i] - 'A' + 1) % MOD) * (mult % MOD)) % MOD;
   }
    if(mult / 10 == 0)
    {
        cout<<'0'<<mult<<"\n";
    }
    else cout<<mult<<"\n";
    return 0;
}
