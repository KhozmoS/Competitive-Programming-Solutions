#include <bits/stdc++.h>

using namespace std;

double l1 , l2;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--){
  cin>>l1;
  l2 = l1 / 2.0;
  l2 = sqrt((l1 * l1) - (l2 * l2));
  l2 *= 2.0;
  double ar = (l1 * l2) / 2.0;
  cout<<setprecision(2)<<fixed<<ar * 3.0<<"\n";
  }
   return 0;
}
