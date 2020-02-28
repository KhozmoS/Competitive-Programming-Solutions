#include <bits/stdc++.h>

using namespace std;

string ar[105];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int ans = 0;
    for(int i = 1 ; i <= t ; i++)
    {
      cin>>ar[i];
      if(i == 1 && ar[i][0] == 's')
        ans++;
      else if(i > 1)
      {
        if(ar[i][0] == 's' && ar[i - 1][0] == 's')
        ans++;
        else if(ar[i][0] == 'r' && ar[i - 1][0] == 'r')
        ans++;
        else if(i > 3 && ar[i][0] == 'r' && ar[i - 1][0] == 'c' && ar[i - 2][0] == 'c' && ar[i - 3][0] == 'c')
        ans++;
        else if (ar[i][0] == 'c' && ar[i - 1][0] == 'c' && (ar[i - 2][0] != 'c' || ar[i - 3][0] != 'c'))
        ans++;
      }
    }

    cout<<ans<<"\n";
}
