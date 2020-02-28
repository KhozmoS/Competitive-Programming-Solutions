#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    while(cin >> a){
    int c=((a*(a+1))*(2*a+1))/6;
    int r=((a*a)*((a+1)*(a+1)))/4;
    cout<<c<<" "<<r<<endl;
    }
    return 0;
}
