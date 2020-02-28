#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL Sum(LL a , LL b)
{

    LL sol = ((b * (b + 1)) / 2) - ((a * (a + 1)) / 2);
    return sol;
}
int main()
{
    LL a , b , x;
    cin>>a>>b;
    x = abs(a - b);
    //cout<<a<<"\n";
    b = (a + b) - 1;
   // cout<<b<<"\n";
    LL sol = Sum(x , b);
    cout<<sol<<"\n";
    return 0;
}
