#include <bits/stdc++.h>

using namespace std;

vector<int> notas;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     int n , q;
     cin>>n>>q;
     int c = 1;
     while(n--)
     {
         int x; cin>>x;

         while(x--)
         notas.push_back(c);

         c++;
     }
      while(q--)
      {
          int i; cin>>i;
          cout<<notas[i]<<"\n";
      }
    return 0;
}
