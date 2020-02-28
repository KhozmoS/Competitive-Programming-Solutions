#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll x , a , b;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
      cin>>b>>x;
      if(x > 32){cout<<-1<<"\n"; continue;}

      a = b - 1;

      for(int i = 1 ; i <= x ; i++)
         a -= (b - a);
      if(a > 0){ cout<<a<<"\n"; continue;}
      a = b + 1;
      for(int i = 1 ; i <= x ; i++)
         a += (a - b);
      if(a < 1e9 + 1){cout<<a<<"\n"; continue;}

      cout<<"-1\n";
    }
    return 0;
}
