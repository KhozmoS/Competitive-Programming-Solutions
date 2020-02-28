#include <bits/stdc++.h>

using namespace std;

int t;
string a , b;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;

    while(t--)
    {
        double a , b;
        cin>>a>>b;

        double sol = a / b;
        printf("%.2lf \n" , sol);
    }
    return 0;
}
