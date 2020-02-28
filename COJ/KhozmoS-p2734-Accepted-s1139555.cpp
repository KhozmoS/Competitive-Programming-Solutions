#include<bits/stdc++.h>

using namespace std;

string cad; int n; int sol;
int main()
{
    while(cin>>cad>>n)
    {
        if(cad[0] == 's')
        sol += n;
        else
        sol -= n;
    }
    cout<<"resultado: "<<sol<<"\n";

    return 0;
}
