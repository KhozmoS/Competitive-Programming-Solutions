#include<bits/stdc++.h>


using namespace std;
 typedef long long ll;

 ll ans[7500];
 int mon[] = {1 , 5 , 10 , 25 , 50};
 int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ans[0] = 1;
    for(int i = 0 ; i < 5 ; i++)
     for(int j = mon[i] ; j <= 7500 ; j++)
      ans[j] += ans[j - mon[i]];

      while(cin>>n) cout<<ans[n]<<"\n";

    return 0;
}
