#include <bits/stdc++.h>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

 int suma=0;
    string P;
    int A;
  while(cin >>P >> A){


          if(P[0]=='s')
            suma+=A;
          else
            suma-=A;

      }
      cout << "resultado" << ":" << ' '<< suma <<"\n";
    return 0;
}
