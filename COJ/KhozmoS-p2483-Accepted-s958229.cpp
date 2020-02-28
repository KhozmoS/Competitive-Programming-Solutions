#include<bits/stdc++.h>


using namespace std;
const int MAXN = 1000005;
typedef long long LL;
int x[4];
int y[4];
int solx;
int soly;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>x[0]>>y[0];
  cin>>x[1]>>y[1];
  cin>>x[2]>>y[2];
  sort(x , x + 3);
  sort(y , y + 3);

  if(x[0] != x[1])
  solx = x[0];
  if(x[0] == x[1])
  solx = x[2];
  if(y[0] != y[1])
  soly = y[0];
  if(y[0] == y[1])
  soly = y[2];

  cout<<solx<<" "<<soly<<"\n";

  return 0;
}
