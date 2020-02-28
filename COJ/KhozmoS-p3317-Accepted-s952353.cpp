#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;
const int MOD =  1000000007;

vector<int> Fib;


int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);
Fib.push_back(1);
Fib.push_back(1);
    int ant = 1;
    int act = 1;
      int i = 2;
      while(i < MAXN)
      {
         int x = ((ant % MOD) + (act % MOD)) % MOD;
         Fib.push_back(x);
         ant = act;
         act = x;
         i++;
      }
      int m;
      cin>>m;
      while(m--)
      {
          int n; cin>>n;

          cout<<Fib[n]<<"\n";
      }
    return 0;
}
