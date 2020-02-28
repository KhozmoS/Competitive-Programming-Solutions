#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db long double

const long double sqrt2 = sqrt(2);

db R;
int K, t;

db getRadio( db x ) {
    return sqrt(2.0*x*x)/2.0;
}
db getSide( db x ) {
    return 2*x;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout<<setprecision(0)<<fixed;
    cin>>t;
    while(t--) {
        cin>>R>>K;
        bool circle = (K&1);
        K--;
        while(K--) {
            if(K&1) {
                R = getRadio(R);
            } else
                R = getSide(R);
        }
        if(circle) {
            cout<<(R*R)<<"PI\n";
        } else {
            cout<<(R*R)<<"\n";
        }
    }
}
