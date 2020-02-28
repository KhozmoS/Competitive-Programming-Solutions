#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double  a, b , c ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> a >> b;
      int N ;
      cin >> N;
      int t = N;
      while(N -- ){
         double d ;
         cin >> d ;
            c += ((a-d)/b);

      }
      cout << setprecision(5) << fixed << t*2 + c;
}