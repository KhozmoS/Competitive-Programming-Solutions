#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int TA[MAXN];
void tabla()
{
 for(int i = 1 ; i < MAXN ; i++)
 {
    int n = i;
     int p = 1;
    while(n != 0)
    {
      p *= n % 10;
      n /= 10;
    }
     if(p % 2 == 0)
     TA[i] += TA[i - 1] + 1;
     else TA[i] += TA[i - 1];
 }
}
 int a , b , t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  tabla();
  cin>>t;
  while(t--){
  cin>>a>>b;
  cout<<TA[b] - TA[a - 1]<<"\n";
  }
    return 0;
}
