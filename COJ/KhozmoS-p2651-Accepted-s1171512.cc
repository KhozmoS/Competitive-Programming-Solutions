#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;

#define db double

db pi = 3.141592654;
db sen = 0.86602540378443864676372317075294 , r;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout<<setprecision(2)<<fixed;
    int t;cin>>t;
    for(int cas = 1 ; t-- ; cas++)
    {
       db per;
       cin>>per;
       db r = per/(2.0*pi);
       db triangle = r*r*sen/2.0;
       db mt = triangle * 3.0;
       cout<<"Case "<<cas<<"\n";
       cout<<"Rice: "<<mt - (triangle/2.0)<<"\n";
       cout<<"Beans: "<<mt + (triangle/2.0)<<"\n";
    }

}
