#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1111111;

set <int> elem;
set <int> :: iterator itr;
bool mk[MAXN];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

   elem.insert(0); elem.insert(1000000);

       int n;cin>>n;
        for(int i = 0 ; i < n ; i++)
        {
          int x;
          cin>>x;
          itr = elem.lower_bound(x);
          itr--;
          if(!mk[x])
            cout<<*itr<<" ";
          else
            cout<<x<<" ";
          itr = elem.lower_bound(x);
          elem.insert(x);
          cout<<*itr<<"\n";
          mk[x] = true;
        }

    return 0;
}
