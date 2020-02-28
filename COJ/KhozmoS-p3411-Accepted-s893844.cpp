#include<bits/stdc++.h>
using namespace std;
 double pi = acos(0) * 2.0;
 int n;
 double rad,circ,cuad,diag;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for(int i = 0; i < n ;i++)
    {
      cin>>rad;
      diag = rad * 2;
      cuad = diag * diag / 2;
      circ = pi * rad * rad;
      double sol = circ - cuad;
      printf("%.2lf\n",sol);
    }
    return 0;
}
