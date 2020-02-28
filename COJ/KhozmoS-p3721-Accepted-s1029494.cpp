#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 30;

ll freq[MAXN];

ll fact(ll x)
{
   ll sol = 1;
   for(ll i = 1 ; i <= x ; i++)
   sol *= i;

   return sol;
}

int t;
int main()
{
   //cout<<fact(20);
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>t;
     int k = 0;
     while(t--)
     {
      ll num;
      string cad;
      cin>>cad;

      num = fact(cad.size());

      for(int i = 0 ; i < cad.size() ; i++)
      freq[cad[i] - 'A']++;

      for(int i = 0 ; i < 27 ; i++)
      if(freq[i] != 0)
      num /= fact(freq[i]);

      cout<<"Data set "<<++k<<": "<<num<<"\n";

      for(int i = 0 ; i < MAXN ; i++)
        freq[i] = 0;

     }
    return 0;
}
