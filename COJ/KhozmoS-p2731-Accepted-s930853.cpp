#include<bits/stdc++.h>

using namespace std;
 const double pi = 3.141592653589793;
 double lads , rad , sol;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lf", &lads);
        rad = lads / 2;
        sol = (lads * lads) - ((rad * rad) * pi);
        printf("%.2lf\n" , sol);
    }
    return 0;
}
//400
