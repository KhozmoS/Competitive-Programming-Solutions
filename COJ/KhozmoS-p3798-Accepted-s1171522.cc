#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double r , pi = acos(-1);

double lado(double a_x , double a_c , double c)
{
    return c * (sin(a_x * pi/180.0) / sin(a_c * pi/180.0));
}

int main() {


    ios_base::sync_with_stdio(0);cin.tie(0);
    double alpha , beta;

    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>alpha>>beta;
        double an_c = 90.0 - alpha;
        double a_x = 180.0 - (an_c + an_c);

        double l3 = lado(a_x , an_c , r);
        double gamma = 180.0 - (alpha + beta);

        double l1 = lado(alpha , gamma , l3);
        double l2 = lado(beta , gamma , l3);

        double s = (l1 + l2 + l3) / 2.0000;
        double ans1 = sqrt(s * (s-l1) * (s-l2) * (s-l3));
        cout<<setprecision(3)<<fixed<<ans1<<" square units\n";
    }
}