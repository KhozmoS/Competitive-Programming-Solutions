#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define db double
db h;int a;
db m;
char c;
db H[25];

int main()
{
    for(int i = 0 ; i <= 24 ; i++){
        H[i] = (db)(i%12);
        //cout<<H[i]<<"\n";
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>a>>c>>m)
    {
       h = H[a];
       db angle_m = 6 * m;
       db angle_h = 30.0 * h + 30.0 / (60.0 / m);
       cout<<setprecision(1)<<fixed<<angle_h<<" "<<angle_m<<"\n";
    }
}
