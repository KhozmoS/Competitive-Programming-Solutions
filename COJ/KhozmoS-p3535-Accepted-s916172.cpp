#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int TA[MAXN];
bool is_prime(long long x)
{
  if(x == 1)
  return false;
  if(x % 2 == 0)
  return false;
  for(long long  i = 3 ; i * i <= x ; i += 2)
  {
    if(x % i == 0)
     return false;
  }
  return true;
}

long long n;
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
   cin>>n;
   if(is_prime(n - 2))
   cout<<"yes\n";
   else
   cout<<"no\n";

  }

return 0;
}
