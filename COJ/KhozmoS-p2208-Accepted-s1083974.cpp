#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e5 + 5;

int ar[MAX];
int n , sol;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>n;
  for(int i = 1 ; i <= n ; i++)
  {
      int x;
      cin>>x;
      ar[x + 1] = i;
  }
  for(int i = 2 ; i <= n ; i++)
    if(ar[i - 1] < ar[i])
    {
       sol = max(sol , ar[i] - ar[i - 1] + 1);
       ar[i] = ar[i - 1];
    }

    cout<<(sol ? sol : -1)<<"\n";
    return 0;
}
