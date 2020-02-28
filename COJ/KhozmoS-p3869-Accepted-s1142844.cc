#include <bits/stdc++.h>

using namespace std;
int ar[1005];
int main()
{
 int t; cin>>t;

 for(int i = 1 ; i <= t ; i++) cin>>ar[i];

 ar[0] = 1;

 int ans = 0;

 for(int i = 1 ; i <= t ; i++)
 {
   ans += abs(ar[i] - ar[i - 1]);
 }
 ans += ar[t] - 1;

 cout<<ans<<"\n";
    return 0;
}
