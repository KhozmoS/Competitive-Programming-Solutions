#include<bits/stdc++.h>


using namespace std;

#define db double
const db eps = 0.000111111111111111111111111111;
db rad , pi = 3.14159265358979323846264338327950000;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    scanf("%lf" , &rad);
    db ans1 = floor(1e4*pi*rad*rad);
    printf("%.4lf\n" , ans1*(1e-4));
    printf("%.4lf\n" , (2.0*rad)*(rad));
}
