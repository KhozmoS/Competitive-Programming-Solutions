#include <bits/stdc++.h>

using namespace std;
double a,b,c;
int t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++){
    cin >> a >> b >> c;


    cout <<"Case #"<<i<<": "<< setprecision(2) << fixed << 2.0*c/(a+b) << "\n";
    }
    return 0;
}
