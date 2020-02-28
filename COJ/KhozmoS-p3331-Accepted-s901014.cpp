#include <bits/stdc++.h>

using namespace std;
long long n , m , N , tot , cfp , cfd ,rest ;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     while(cin>>n>>m , n && m){
      if(n == 1 && m == 1)
        cout<<'0'<<"\n";
     else if(n >= 2 && m >= 2)
     {
         tot = n * m;
         tot = tot * (tot - 1);
         cfp = (m * (2 * (n - 1))) + (n * (2 * (m - 1)));
          if(n >= m){
            cfd = ((((n - 1) * 2) * 2) * (m - 1));
          }
          else
            cfd = ((((m - 1) * 2) * 2) * (n - 1));
          rest = cfp + cfd;
         // cout<<tot<<" "<<cfp<<" "<<cfd<<"\n";
          cout<<tot - rest<<"\n";
     }
      else
      {
          tot = n * m;
          tot = tot * (tot - 1);
          cfp = (m * (2 * (n - 1))) + (n * (2 * (m - 1)));
          cout<<tot - cfp<<"\n";
      }
     }
        return 0;
}
