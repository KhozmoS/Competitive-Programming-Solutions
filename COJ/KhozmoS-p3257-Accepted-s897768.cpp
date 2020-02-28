#include <bits/stdc++.h>

using namespace std;

int main()
{
    double l1,l2,l3;
    cin>>l1>>l2>>l3;
     double  sp1 = (l1 * 3)/2;
     double sp2 = (l2 * 3)/2;
     double sp3 = (l3 * 3)/2;
    double A1 = sqrt( sp1*(sp1-l1)*(sp1-l1)*(sp1-l1));
    double A2 = sqrt( sp2*(sp2-l2)*(sp2-l2)*(sp2-l2));
    double A3 = sqrt( sp3*(sp3-l3)*(sp3-l3)*(sp3-l3));
       double r1 = A1/sp1;
       double r2 = A2/sp2;
       double r3 = A3/sp3;
       double ac1 = 3.14159265389 *(r1 * r1);
        double ac2 = 3.14159265389 *(r2 * r2);
         double ac3 = 3.14159265389 *(r3 * r3);
      double spi = (l1 + l2 + l3)/2;
        double A4 = sqrt( spi*(spi-l1)*(spi-l2)*(spi-l3));
        double r4 = A4 / spi;
        double ac4 = 3.14159265389 *(r4 * r4);
        double sol = ac1 + ac2 +ac3 + ac4;
         printf("%.3lf",sol);

    return 0;
}

