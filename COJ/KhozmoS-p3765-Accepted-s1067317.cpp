#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int mod = 1000000007;



int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
     string cad;
     cin>>cad;
      int sol = 0;

     for(int i = 0 ; i < cad.size() ; i++)
     {
       if(cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'i' || cad[i] == 'o' || cad[i] == 'u')
       continue;

        sol += (cad[i] - 'a' + 1);

     }
       cout<<sol<<"\n";
    return 0;
}
