#include <bits/stdc++.h>

using namespace std;

const int MAX =  1005;


bool is_prime(int x)
{
    if(x == 1 || x == 2)
        return true;
    if(x == 0) return false;

    if(x % 2 == 0) return false;

    for(int i = 3 ; i * i <= x ; i += 2)
        if(x % i == 0)
        return false;

    return true;
}

vector <int> sol;
int main()
{
 ios_base::sync_with_stdio();cin.tie(0);

  int a , b;
  cin>>a>>b;

  while(a != 0)
  {
    if(is_prime(a % b))
     sol.push_back(a % b);

    a /= b;
  }
  cout<<sol.size()<<" ";
   if(!sol.size()) return 0;
  sort(sol.begin(),sol.end());

  for(int i = 0 ; i < sol.size() - 1 ; i++)
    cout<<sol[i]<<" ";

  cout<<sol[sol.size() - 1]<<"\n";
    return 0;
}
