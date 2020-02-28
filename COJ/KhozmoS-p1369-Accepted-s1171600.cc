#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define db double
const db pi = acos(-1);
const db sen = sin(60 * pi/180);
db l , n , k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>l>>n>>k && k != 0.0)
    {
        db big = l * l * sen / 2.0;
        db p = l / n;
        db l1 = k*p;
        db l2 = (n-k) * p;
        db les = l1 * l2 * sen / 2.0;
        cout<<setprecision(0)<<fixed<<big - (3*les)<<"\n";
    }
}
