#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long double ld;

const double g = 9.8;
const double pi = 3.1415926535897932384626433832795;
const double convert = 57.295779513082320876798154814105;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ld x0, y0, x, y, v, alpha1, alpha2, a, b, c, d;
    while(cin >> x0 >> y0 >> x >> y >> v){
        x -= x0;
        y -= y0;
        v *= v;
        a = g * x * x / v;
        b = 2 * x;
        c = 2 * y + a;
        d = b * b - 4 * a * c;
        if(d < 0)
            cout << "Impossible" << endl;
        else{
            if(x != 0){
                alpha1 = atan((b - sqrt(d)) / (2 * a)) * convert;
                alpha2 = atan((b + sqrt(d)) / (2 * a)) * convert;
                if(alpha1 < 0 || alpha1 > 90)
                    alpha1 = alpha2;
                if(alpha1 >= 0 && alpha1 <= 90){
                    cout.precision(2);
                    cout.setf(ios::fixed);
                    cout << alpha1 << endl;
                }
                else
                    cout << "Impossible" << endl;
            }
            else{
                if(v - 2 * g * y < 0)
                    cout << "Impossible" << endl;
                else
                    cout << (y > 0 ? "90.00" : (y == 0 ? "0.00" : "Impossible")) << endl;
            }
        }
    }
    return 0;
}