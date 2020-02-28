#include <bits/stdc++.h>

using namespace std;

long long pot(long long x)
{
    long long a = 2;
    long long sol = 1;
    if(x == 0)
        return 1;
 for(int i = 0 ; i < x ; i++)
    sol *= a;

    return sol;
}

 int main()
 {
  long long n;
  cin>>n;
  cout<<n + 1;

    return 0;
}
