#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

bool crib[MAX];
vector <int> fac;
long long t, n, x[MAX] , y[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n){

      for(int i = 0 ; i < n ; i++)
            cin>>x[i]>>y[i];

      sort(x , x + n);
      sort(y , y + n);

      long long x1 = x[n / 2];
      long long y1 = y[n / 2];
      long long ans = 0;
      for(int i = 0 ; i < n ; i++)
      {
          ans += abs(x1 - x[i]);
          ans += abs(y1 - y[i]);
      }


     cout<<ans<<"\n";
    }


}
