#include<bits/stdc++.h>


using namespace std;

#define db double
const db eps = 0.000111111111111111111111111111;
db rad , pi = 2.0*acos(0);

int main()
{
    //cout<<setprecision(4)<<fixed<<2.0*acos(0)<<"\n";
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>rad;
    db ans1 = pi*rad*rad;
    cout<<setprecision(4)<<fixed<<ans1-0.00005<<"\n";
    cout<<setprecision(4)<<fixed<<(2.0*rad)*(rad)<<"\n";
}
