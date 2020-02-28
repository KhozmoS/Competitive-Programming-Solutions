#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;


int abi[MAX] , q[MAX];

void update(int pos , int x)
{
    for(int i = pos ; i < MAX ; i += (i & -i))
      abi[i] += x;
}
int sum(int x)
{
  int s = 0;
  for(int i = x ; i > 0 ; i -= (i & -i))
    s += abi[i];

  return s;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
     for(int i = 0 ; i < n ; i++)
     {
         int a , b;
         cin>>a>>b;
         if(a > b)
         swap(a , b); 
         int sol1 = sum(a); int sol2 = sum(b);

         update(a + 1 , 1); update(b , -1);
         cout<<sol1 + sol2 - (q[a] + q[b])<<"\n";

         q[a] = sol1; q[b] = sol2;
     }
  return 0;
}

