#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;


int MAT[MAXN][MAXN];

int a , b , nod , arist;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

   long long n , m;

    while(cin>>n>>m)
    {
      long long cantt = 0;
      cantt += (n * (n - 1) / 2) * m;
      cantt += (m * (m - 1) / 2) * n;

      long long cantc = ((n * (n - 1) / 2)) * (m * (m - 1) / 2);

     // cout<<cantt<<" "<<cantc;
     cout<<"Triangles: "<<cantt<<"\n";
     cout<<"Quadrilaterals: "<<cantc<<"\n";
     cout<<"\n";
    }
    return 0;
}
