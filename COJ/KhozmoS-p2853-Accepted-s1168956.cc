#include<bits/stdc++.h>


using namespace std;

#define db double
const db eps = 0.0000000001;
db c;
db area(db x)
{
    return (x*x) / 2.0;
}
db sq(db x)
{
    return x*x;
}
int pitagoras(db cat , db tot)
{

    db hip = tot - (2.0*cat);

    if(hip < 0) return -1;

    if(sq(cat) + sq(cat) >= sq(hip))
        return 1;

    return -1;
}
db binary(db x)
{
    db in = 0.0; db fn = x;

    while(in + eps < fn)
    {
        db mt = (in + fn) / 2.0;

        if(pitagoras(mt , x) >= 0)
            fn = mt;
        else
            in = mt;
    }

    return fn;
}

int main()
{
    while(cin>>c)
    {
        if(c == 0) return 0;
        db triangle_side = binary(c);

        cout<<setprecision(3)<<fixed<<(c*c) - (4.0*(area(triangle_side)))<<"\n";
    }
}
