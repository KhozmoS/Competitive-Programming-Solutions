#include <bits/stdc++.h>

using namespace std;
int N , L , W , t;
int main()
{
    cin>>t;
  while(t--)
  {
     cin>>N>>L>>W;
     N++;
     cout<<(N * (N + 1) / 2) * (L * W)<<"\n";
  }

    return 0;
}
