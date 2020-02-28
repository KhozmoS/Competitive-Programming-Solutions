#include<bits/stdc++.h>
#define MAXN 1007
using namespace std;
int x[MAXN] ; int y[MAXN];
int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
      for(int i = 0 ; i < n ; i++)
       cin>>x[i]>>y[i];
      for(int i = 0 ; i < n - 2 ; i++)
      {
        if(((x[i + 1] - x[i]) * (y[i + 2] - y[i]) - (x[i + 2] - x[i]) * (y[i + 1] - y[i])) > 0)
         cout<<"left\n";
        else
         cout<<"right\n";
      }
    return 0;
}
