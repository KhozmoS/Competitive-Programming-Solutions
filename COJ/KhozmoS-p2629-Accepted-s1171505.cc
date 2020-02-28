#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;

#define db double

db pi = acos(-1);
db sen = 0.86602540378443864676372317075294 , r;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>r)
    {
        r /= 2.0;
        db s = (r*3.00) / 2.00;
        db triangle = sen * r * r / 2.00;;
        db cake = pi * r * r * 60.0 / 360.0;
        cout<<setprecision(3)<<fixed<<3*cake - (2*triangle)<<"\n";
    }

}
