#include<bits/stdc++.h>

using namespace std;
const double pi =  	3.14159265358979323846;
double t , n , r , h , v , sumv;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
      cin>>n;
      while(n--)
      {
          scanf("%lf%lf" ,&r, &h);
          v = (pi * (r * r)) * h;
          sumv += v;
      }
      printf("%.2lf\n", sumv);
      sumv = 0;
    }
    return 0;
}
/*100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100*/
