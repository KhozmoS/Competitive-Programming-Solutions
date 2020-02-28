#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;


double TQ , a , b , c;
int t;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>t;

  while(t--)
  {
      cin>>a>>b>>c;
      TQ = ((b + c - a) * (a + b - c) * (c + a - b)) / (a * b * c);
      if(TQ == 1) cout<<"equilateral\n";

      else if(0.5 < TQ && TQ < 1) cout<<"good\n";

      else cout<<"bad\n";
  }

    return 0;
}
