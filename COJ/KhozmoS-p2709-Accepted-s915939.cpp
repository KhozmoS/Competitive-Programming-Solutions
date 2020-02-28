#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;
 bool mk[MAXN];
 int N , P , x , cont;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    cin>>P;
    for(int i  = 0 ; i < P ; i++)
    {
      cin>>x;
      if(!mk[x])
      {
          mk[x] = true;
          cont++;
      }
    }
    cout<<N - cont<<"\n";
    return 0;
}
