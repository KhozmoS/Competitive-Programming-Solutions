#include<bits/stdc++.h>


using namespace std;
 typedef long long LL;

 LL sol[7500];
 int mon[] = {1 , 5 , 10 , 25 , 50};
 int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    sol[0] = 1;
    for(int i = 0 ; i < 5 ; i++)
     for(int j = mon[i] ; j <= 7500 ; j++)
      sol[j] += sol[j - mon[i]];

      while(cin>>n) cout<<sol[n]<<"\n";

    return 0;
}
