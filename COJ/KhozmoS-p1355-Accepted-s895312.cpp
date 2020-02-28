#include <bits/stdc++.h>

using namespace std;
 double rad ,lad ,ladt ,h ,parc , atri ,cua;
int main()
{
   while( cin>>lad ){
    rad = lad / 3;
    parc = (3.141592653589793 * (rad * rad)) / 4;
    // printf("%.4lf\n",parc);
    ladt = lad / 3;
    cua = lad * lad;
    h = lad / 2;
    atri = ladt * h / 2;
    double sol = cua - ((atri * 4) + (parc * 4));
    printf("%.4lf\n",sol  );
    }
    return 0;
}
